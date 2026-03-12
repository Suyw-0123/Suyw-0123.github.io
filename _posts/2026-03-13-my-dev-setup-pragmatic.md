---
layout: page
title: "My Dev Setup"
date: 2026-03-13
categories: [DevSetup, Workflow]
---

In the world of development environments, it is easy to get lost in hyper-customized setups and aesthetic perfection. However, for those of us who prioritize results over "ricing," a pragmatic and robust setup is the true key to productivity. Here is a look into my current development environment—built for reliability, consistency, and professional rigor.

### 1. The Powerhouse: Hardware & Multitasking
My primary machine is a high-performance laptop powered by an **AMD AI 7 350** processor, an **RTX 5060 Laptop GPU**, and **32GB of RAM**. 

While many focus on raw gaming power, these specs are crucial for my multitasking-heavy workflow. Having 32GB of RAM allows me to run multiple resource-intensive applications simultaneously without any lag, ensuring a seamless transition between the Windows host and the Linux guest environment.

### 2. The OS: The Best of Both Worlds with WSL2
I run **Windows 11 Pro** as my base operating system, primarily because it offers the widest compatibility for general productivity tools. However, for my core development work, I rely exclusively on **WSL2 (Windows Subsystem for Linux)**.

I use **Ubuntu LTS** as my primary distribution. The reasons are simple:
*   **Environmental Consistency:** Most production servers run Ubuntu or similar Debian-based systems. Developing locally on the same architecture eliminates the "it works on my machine" syndrome.
*   **Superior CLI Toolchain:** Linux offers a significantly more robust ecosystem for command-line tools compared to native Windows.
*   **Ease of Use:** Ubuntu is well-supported, and finding solutions for any environment-specific issue is straightforward.

### 3. The Editor: Why I Returned to VS Code
My journey with editors has seen various experiments, including high-performance tools like **Antigravity**. Yet, I eventually found my way back to **VS Code**. 

VS Code strikes the perfect balance between extensibility and stability. I prefer manually tailoring my environment rather than using pre-packaged "super-distributions." My setup is minimalist:
*   **Theme:** **One Dark Pro** with the **Night Flat** variant. It provides a low-contrast, eye-friendly color palette that remains comfortable during long coding sessions.
*   **Extensions:** I keep my extensions lean, focusing only on essential language support and core productivity tools.

### 4. The Workflow: Specification-Driven Development (SDD)
The most critical part of my setup isn't the hardware or the editor—it's the **Workflow**. I use a combination of **OpenCode** (an interactive CLI agent) and **OpenSpec** (a specification-driven development framework).

When addressing a bug or implementing a feature (even in an existing open-source project), I follow a rigorous process:
1.  **OpenSpec Analysis:** Before writing any code, I use OpenSpec to analyze the issue, identify the root cause, and draft a solution proposal.
2.  **Approval Gate:** No changes are executed until the solution report is approved. This ensures a clear plan of action.
3.  **Execution with OpenCode:** OpenCode handles the execution of changes based on the specification, maintaining strict logs and audit trails.
4.  **Verification:** The workflow mandates unit and integration testing. Every change is verified against the original specification.
5.  **Documentation & Pull Request:** The entire "walkthrough" of the change—from reasoning to verification—is recorded. This makes creating a high-quality Pull Request trivial, as all the necessary context and justification are already documented in the spec.

### Conclusion
A great development setup isn't about the flashiest UI or the most obscure toolchain. It’s about creating a stable, repeatable, and rigorous environment that allows you to focus on solving problems. By combining the flexibility of VS Code, the power of WSL2, and the rigor of Specification-Driven Development, I’ve found a workflow that truly supports professional growth and code quality.

---

