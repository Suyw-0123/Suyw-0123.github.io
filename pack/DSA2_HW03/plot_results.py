import pandas as pd
import matplotlib.pyplot as plt
import os

def generate_plots(csv_path, output_dir):
    
    df = pd.read_csv(csv_path)
    
    avg_df = df.groupby(['algorithm', 'n'])['elapsed_ms'].mean().reset_index()

    if not os.path.exists(output_dir):
        os.makedirs(output_dir)

    algorithms = avg_df['algorithm'].unique()

    for algo in algorithms:
        algo_data = avg_df[avg_df['algorithm'] == algo]
        
        plt.figure(figsize=(10, 6))
        plt.plot(algo_data['n'], algo_data['elapsed_ms'], marker='o', linestyle='-')
        
        plt.xlabel('List size (n)')
        plt.ylabel('Execution time (ms)')
        plt.grid(True, which="both", ls="-", alpha=0.5)
        
        filename = f"{algo.lower()}.png"
        save_path = os.path.join(output_dir, filename)
        
        plt.savefig(save_path)
        plt.close()
        print(f"Generated plot: {save_path}")

if __name__ == "__main__":

    script_dir = os.path.dirname(os.path.abspath(__file__))
    csv_file = os.path.join(script_dir, "benchmark_output.csv")
    plots_folder = os.path.join(script_dir, "plots")
    
    generate_plots(csv_file, plots_folder)
