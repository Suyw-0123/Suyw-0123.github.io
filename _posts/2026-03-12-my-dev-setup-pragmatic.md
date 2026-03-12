---
layout: page
title: "My Pragmatic Dev Setup: WSL2, VS Code, and Rigorous Workflow"
date: 2026-03-12
categories: [DevSetup, Workflow]
---

Development setups are highly personal. For me, productivity is about stability and a predictable workflow rather than aesthetic customization. Here is how I’ve configured my environment to stay efficient.

### Hardware & Performance
I use a laptop with an **AMD AI 7 350**, an **RTX 5060**, and **32GB of RAM**. 

For my multitasking-heavy habits, the 32GB of RAM is the most critical spec. It provides enough headroom to keep my Windows host and WSL2 environment responsive while running multiple containers, browsers, and developer tools simultaneously.

### OS: Windows 11 + WSL2 (Ubuntu)
I prefer **Windows 11 Pro** for general productivity, but all my development happens in **WSL2**. 

I chose **Ubuntu LTS** as my distro for its familiarity and its alignment with most production server environments. It offers a robust CLI toolchain that is simply more efficient for development than native Windows.

### Editor: VS Code
I’ve experimented with other editors like **Antigravity**, but I keep returning to **VS Code**. I find it more satisfying to manually configure my own environment from scratch.
*   **Theme:** **One Dark Pro** with the **Night Flat** variant. It’s a low-contrast, eyes-friendly choice that works well for me.
*   **Approach:** I keep my configuration lean, installing only the extensions I use daily.

### Workflow: OpenSpec & OpenCode
The core of my setup is a rigorous, specification-driven workflow using **OpenCode** and **OpenSpec**. While it adds more steps than a typical coding process, it significantly increases my confidence in the final result.
1.  **Reasoning:** I use OpenSpec to analyze the problem and document the "why" before writing code.
2.  **Solution Approval:** Changes are based on a documented solution report, which ensures a clear plan.
3.  **Traceability:** Every modification is logged, tested, and verified. Having a complete walkthrough in a Pull Request makes the review process transparent and reliable.

### Conclusion
This setup is built for my own needs—pragmatic, slightly rigid, and focused on code quality. It’s what works for me.

---

