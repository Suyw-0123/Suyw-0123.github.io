# 關於這份DEMO作業整理:

前情提要: 裡面的寫法是屬於半現代化C++ 寫法，某些地方當然可以用其他更加常見的寫法，我也有大概講一下
我的撰寫順序是按照 main 主函式的順序來寫，可以先翻到 main function 開始配合進食。

#### 變數宣告

大概看一下我們等一下調用的變數類型以及命名，也可以先去看下面的程式碼再上來看

```cpp
using IntList = std::vector<int>;
using BenchmarkClock = std::chrono::steady_clock;

struct BenchmarkResult {
    std::string algorithm;
    int n;
    int run;
    double elapsed_ms;
};
```


### 1. 數組產生函數

這個函數是用來存我們之後要去跑演算法的 n 的大小，因為我們要跑很多輪來測試不同大小的 n，所以需要一個函數能讓我們方便的產生數組， buildRangeSizes(int start, int end, int step)裡面的三個參數可以自己去設置大小，我在這個參數設定就跑到一個比較好的數據結果，畫出來的圖也是比較直觀的。

```cpp
// 用 size 為名字的 vector 數組存我們等一下實作要用的 n 的大小，呼叫buildRangeSizes()函數
std::vector<int> sizes = buildRangeSizes(10000, 500000, 10000);
// buildRangeSizes() 函數被呼叫，例如我們放入的參數是 (10000, 500000, 10000)
// 代表數組的第一個元素是 10000，並且每次繼續塞入比前一個元素還要大 10000 的元素，最後一個元素是 500000
std::vector<int> buildRangeSizes(int start, int end, int step) {
    std::vector<int> sizes;
    for (int n = start; n <= end; n += step) {
        sizes.push_back(n);
    }
    return sizes;
}
// 最後執行完之後 size 這個數組裡面會是 {10000, 20000, 30000, ... , 500000}
```

### 2. repeat (option)

這個變數是用來改善我們之後畫出來圖之後的曲線，例如我設定 repeat = 3，且當下迴圈的 n = 10000，他就會把每一個演算法在 n = 10000 所執行的時間跑三次，並把三次的結果都印出來，我們之後寫 python matplotlib 畫圖，就可以將數據中的這三次取平均，讓他比較不會因為電腦的原因，跑出比較極端的執行時間時表現突兀。
其實這個可寫可不寫，作業說明也沒有要求，每個演算法只跑一次就能得到很好的結果當然很好，就不需要這個功能。

```cpp
int repeats = 3;
```

### 3. 伪隨機數種子

先講最常見的隨機數取種子方法，就是用時間來當作種子丟進srand()函數裡面來設定，確保我們去調用伪隨機函數會因為時間的不同，每次都能返回隨機的數字
再來我的寫法是用硬體噪聲來取種子的方法，可以把 std::random_device{}()，這坨是當作他會返回一個真隨機數，其中std::random_device{} 是建立 random 庫裡面的一個物件，然後我們寫的後面有加上 ()，代表我們要調用它了，而他返回的類型是 uint32_t ，人話叫做不帶正負號的 32 位元整數。我們得到的seed 就會變成我們之後的 mt19937 這個伪隨機演算法的的種子，現在先把它當作 rand() 進化版就好，等一下會說。
當然裡面的種子可以換成其他方法，例如說 ctime 庫裡面的 clock()

```cpp
// 這是我的原始碼寫法
// static_cast<std::uint32_t>() 這個函數是靜態轉型，
// 就是把 std::random_device{}()這坨返回的值轉成 uint32_t 的類型，
// static_cast<>尖括號裡面放什麼類型，他就會把得到的值轉成什麼類型，
// 例如裡面寫的是 uint32_t，seed 裡面就會存 uint32_t 類型的值
// 當然也可以直接用 int 直接轉型，靜態轉型只是避免錯誤寫的比較穩的寫法
std::uint32_t seed = static_cast<std::uint32_t>(std::random_device{}());
```

### 4. 伪隨機演算法 mt19937

在程式碼中，我們建立一個名叫 dataRng 的物件，他是屬於 mt19937 的類別，理解為把剛剛生成的 seed 丟進 mt19937 的伪隨機演算法他的物件 dataRng 裡面，我們每次調用 dataRng 就能得到隨機數字。

```cpp
std::mt19937 dataRng(seed);
```

### 5. 輸出迴圈

大概知道兩層迴圈怎麼跑就好，看原始碼比文字說明還是更加清楚

```cpp
    std::cout << "algorithm,n,run,elapsed_ms" << '\n';

    for (int n : sizes) {
        for (int run = 1; run <= repeats; run++) {
                // code
                // alg1...
                // alg2...
                // alg3...
        }
    }
```

這是運行之後的輸出格式範例

```csv
algorithm,n,run,elapsed_ms
HeapSort,10000,1,0.690678
InsertionSort,10000,1,9.751384
QuickSort,10000,1,0.614413
HeapSort,10000,2,0.709359
InsertionSort,10000,2,8.350113
QuickSort,10000,2,0.608011
HeapSort,10000,3,0.745475
InsertionSort,10000,3,7.955664
QuickSort,10000,3,0.597552
......
.........
```

### 6. 隨機數組產生器 (重要)

前面我們已經宣告好 using IntList = std::vector<int>; ，所以之後看到 IntList 就把它當做 vector 數組就好。
在程式碼中 我們用名叫 base 的數組來存我們題目要求的 1 ~ 50000 的隨機數，然後我們用到了 generateRandomList() 函數的返回數組來存入 base 數組裡面，參數輸入需要的隨機數組大小、以及生成的隨機數的範圍、還有剛剛建立的 dataRng 物件的引用，用來生成隨機數，最後這個函數會返回根據參數的數組。

```cpp
// 調用函數 generateRandomList()
IntList base = generateRandomList(n, 1, 50000, dataRng);

IntList generateRandomList(int size, int minValue, int maxValue, std::mt19937 &rng) {
    // 先簡而言之，宣告 dist 為 std::uniform_int_distribution<int> 這坨類別的物件
    // 而這坨東西的 dist 物件可以設定傳入數值後返回的最大最小值，
    // 例如我們今天要從 dataRng 這個物件取得一個 1 ~ 50000 的數字，
    // 而 dataRng 返回的數字介於 0 到 4,294,967,295 之間，我們有極大可能取得不在我們要的範圍的值
    // 如果我們把 dataRng 生出來的隨機數丟進 dist() 裡面她就會返回 1~50000 的數字，
    // 其實這裡直接用 modulo 取模也行，結果上大機率不會變(如果是以程式碼裡面的參數舉例的話)
    // 那為什麼用 std::uniform_int_distribution 這個 random 庫 template 呢，請詳見下面的說明
    std::uniform_int_distribution<int> dist(minValue, maxValue);
    // 將已經調整的dataRng生成的數字依序放進 value
    IntList values(size);
    for (int i = 0; i < size; i++) {
        values[i] = dist(rng);
    }
    // 返回數組
    return values;
}


```

#### 補充： STL 隨機庫 uniform_int_distribution (可選擇觀看)

延續剛剛的話題，不管是常見的 rand() 方法還是這個程式碼裡面用到隨機庫 mt19937 算法，
其中rand() 在 Windows Kernel 的系統返回值範圍是 0 ~ 2^15 -1 = 32,767, 在 Linux kernel 系統通常是 0 ~ 2^31-1 = 2,147,483,647；mt 19937 演算法無論系統內核，返回值介於 0 到 4,294,967,295 之間，
我們要取得在範圍內的整數，常見的方法就是取模 modulo，但是可能出現 modulo bias，簡單舉個例子，我現在有一個Pseudo RNG 他所產生的隨機數在 0 ~ 8 之間，然後我想要調用這個Pseudo RNG 在經過處理產生 0 ~ 3 之間的整數，如果我使用取 modulo 的方法，對5取模，那麼我得到的每一個整數的機率相同嗎？
RNG out with modulo:
- 0 mod 4 = 0
- 1 mod 4 = 1
- 2 mod 4 = 2
- 3 mod 4 = 3
- 4 mod 4 = 0
- 5 mod 4 = 1
- 6 mod 4 = 2
- 7 mod 4 = 3
- 8 mod 4 = 0

看的出來我得到集合{0} 的機率比集合 {1, 2, 3} 來的大 ，所以當對 RNG 的最大返回值是目標返回範圍大小除不盡的時候就會出現每個值返回機率不同，
如果使用 uniform_int_distribution，概念上它不會單純做取模，他會對於有 bias 範圍捨棄後重抽，一樣的例子

uniform_int_distribution：
- 0 mod 4 = 0
- 1 mod 4 = 1
- 2 mod 4 = 2
- 3 mod 4 = 3
- 4 mod 4 = 0
- 5 mod 4 = 1
- 6 mod 4 = 2
- 7 mod 4 = 3
- 8 mod 4 = // 在這裡發現這是會出現 bias 的值，所以會再次呼叫 Pseudo RNG 再跑一次

因此最後回傳 0、1、2、3 的長期機率會趨近相同，不會像只取 modulo 那樣 0 出現的機率變高。
題目要求使用的是 1~50000 的取值區間，因為rand()最大返回值(我使用的是WSL的環境，所以返回值 0 ~ 2,147,483,647)是不能被目標返回範圍大小(1~50000)整除，使用 uniform_int_distribution 相對來說數學上比較嚴謹。
最後再說一下，在實務上， srand(time)取種子並使用rand()方法然後取要求範圍的模的結果 跟 硬體噪聲取種子並使用 mt 19937 演算法然後用uniform_int_distribution取範圍去跑這個程式碼並不會有太大差別。


### 7. 計時方法

這裡使用 chrono 庫來計時，一開始我們有宣告 BenchmarkClock 是 std::chrono::steady_clock 的別名，這個類別適合用來去做精確的計時，裡面的 now() 調用他的時間返回的時間沒有什麼意義，他可能是電腦開機到現在的時間或是其他，然後我們去計算兩個時間差的時候要用 std::chrono::duration<double, std::milli> 類別來記錄，duration 裡面有選擇存的類型根單位，例如裡面存的 double 類型與 milli 毫秒單位，我們最後儲存在 elapsed 物件裡面，我們在輸出的時候加上 std::fixed << std::setprecision(6) ，代表只記錄小數點後第六位，最後 elapsed 要加上 .count() 方法，因為我們之前說過這是一個物件。
當然這個方法也能用 ctime 裡面的 clock() 方法來替代，他的類型 clock_t 精度是微渺。

```cpp
using BenchmarkClock = std::chrono::steady_clock;

IntList values = base;

auto start = BenchmarkClock::now();
heapSort(values);
auto end = BenchmarkClock::now();

std::chrono::duration<double, std::milli> elapsed = end - start;
                std::cout << "HeapSort," << n << ',' << run << ',' << std::fixed << std::setprecision(6) << elapsed.count() << '\n';
```

### 8. 驗證 (option)

這是用來驗證演算法有沒有正確排序的函式，自己寫完不同的演算法可以用這個函數驗證一下，注意，這是用來驗證升序排列的，如果要驗證降序的話把大於改成小於就好
替代的話，標準庫也有 std::is_sorted 來驗證
另外，這個部分不在於作業要求裡面，也可以不實做這個部分。

```cpp
 if (!isSortedAscending(values)) {
    std::cerr << "HeapSort failed to sort correctly for n=" << n << '\n';
    return 2;
}

bool isSortedAscending(const IntList &arr) {
    for (int i = 1; i < static_cast<int>(arr.size()); ++i) {
        if (arr[i - 1] > arr[i]) {
            return false;
        }
    }
    return true;
}
```


### 9. 演算法實作 (核心) 

我分配到的演算法組合是 Insertion Sort + Heap Sort + Quick Sort
如果有分配到其他演算法的話，程式碼都在課本裡面有，裡面講的都很完整
這裡我只會大概講一下而已我寫的演算法長什麼樣子

#### InsertionSort

傳入未排列的數組引用，首先 static_cast<int>(arr.size())，其中 arr.size()， .size() 方法是回傳數組元素量且是 size_t 類別，然後套在靜態轉型static_cast<int>變成整數，接下來裡面的東西比較像課本上的東西，但是課本上面把 insert() 寫成一個函數，我這裡是寫在一起了。
想像這就像是玩打牌遊戲，發到的牌需要排序，裡面的 key 變數相當於在排序時用手把一張牌拿起來的那一張，然後我們把它放到合適的位置，並用 for 回圈套住

```cpp
void insertionSort(IntList &arr) {
    for (int i = 1; i < static_cast<int>(arr.size()); i++) {
        int key = arr[i];
        int j = i;
        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}
```

#### HeapSort

heap sort 大概的流程是 先構建 heap tree ，然後 swap (root, last) 再構建再swap (root, last) 再構建...... and so on，可以從 heapSort() 函數裡面看出來
注意一下，因為傳進來的數組的第一個元素 index 為 0，而課本上的 heap tree 的 root 要為 1，後來的左子樹與右子樹才能分別是 2n, 2n+1，所以在實作時比較環節我們直接對 index 減 1 來對應 vector 的 0-based 索引。

```cpp
void heapifyDown(IntList &arr, int heapSize, int rootIndex) {
    while (true) {
        int largest = rootIndex;
        int left = 2 * rootIndex;
        int right = 2 * rootIndex + 1;

        if (left <= heapSize && arr[left - 1] > arr[largest - 1]) {
            largest = left;
        }
        if (right <= heapSize && arr[right - 1] > arr[largest - 1]) {
            largest = right;
        }

        if (largest == rootIndex) {
            break;
        }

        std::swap(arr[rootIndex - 1], arr[largest - 1]);
        rootIndex = largest;
    }
}

void heapSort(IntList &arr) {
    const int n = static_cast<int>(arr.size());
    if (n <= 1) {
        return;
    }

    for (int i = n / 2; i > 0; i--) {
        heapifyDown(arr, n, i);
    }

    for (int i = n; i > 1; --i) {
        std::swap(arr[0], arr[i - 1]);
        heapifyDown(arr, i - 1, 1);
    }
}
```

#### QuickSort

就三個函數，主函數 quickSort() 條件呼叫 quickSortImpl() ， implementation 用 recursive 對 partition() 遞迴之後的數組，課本裡面有用雙指針swap的方法

```cpp
int medianOfThreeIndex(const IntList &arr, int low, int high) {
    int mid = low + (high - low) / 2;
    int a = arr[low];
    int b = arr[mid];
    int c = arr[high];

    if ((a <= b && b <= c) || (c <= b && b <= a)) {
        return mid;
    }
    if ((b <= a && a <= c) || (c <= a && a <= b)) {
        return low;
    }
    return high;
}

int partition(IntList &arr, int low, int high) {
    int pivotIndex = medianOfThreeIndex(arr, low, high);
    int pivotValue = arr[pivotIndex];
    std::swap(arr[pivotIndex], arr[high]);

    int storeIndex = low;
    for (int i = low; i < high; ++i) {
        if (arr[i] < pivotValue) {
            std::swap(arr[i], arr[storeIndex]);
            ++storeIndex;
        }
    }

    std::swap(arr[storeIndex], arr[high]);
    return storeIndex;
}

void quickSortImpl(IntList &arr, int low, int high) {
    if (low >= high) {
        return;
    }

    int p = partition(arr, low, high);

    if (p > 0) {
        quickSortImpl(arr, low, p - 1);
    }
    quickSortImpl(arr, p + 1, high);
}

void quickSort(IntList &arr) {
    if (arr.size() <= 1) {
        return;
    }
    quickSortImpl(arr, 0, static_cast<int>(arr.size()) - 1);
}
```

