---
layout: page
title: "My RAG Development Journey: From Exploration to Graph RAG"
date: 2026-01-09
tags: ["RAG", "Graph RAG", "Golang", "Kubernetes", "DevLog"]
---

This is a journey of how I evolved from an LLM (Large Language Model) enthusiast to a RAG system developer. From understanding the core principles to implementing cloud-native microservices, every step represents my growth and thinking in technology.

## 1. The Beginning: First Taste of RAG
I discovered RAG (Retrieval-Augmented Generation) on GitHub and was instantly fascinated by its ability to mitigate LLM hallucinations. This marked the start of my learning journey, where I built my first experimental repo: **[RAG-explore](https://github.com/Suyw-0123/RAG-explore)**. At this stage, I focused on understanding Vector Embeddings and the basic logic of retrieval.

## 2. Practice: Stepping into Web Development
As I acquired web development skills at school, I began thinking about how to transform RAG into a real-world application. I developed **ChatYourNotes**, marking my first attempt to bring a RAG system to a web interface with local network deployment. This taught me that great technology needs a good user interface to truly shine.

## 3. Advancement: Integrating Stack and Architecture
Next, I expanded my tech stack to pursue a more professional architecture:
*   **Frontend**: Built a modern UI with React.
*   **Backend**: Handled logic with Flask.
*   **Data Storage**: Integrated ChromaDB for vectors and MySQL for metadata.
*   **Engineering**: Leveraged **Docker Compose** to orchestrate full-stack services.
*   **Data Processing**: Introduced OCR to parse text directly from PDF files.
The goal of this phase was to build a stable, end-to-end RAG application.

## 4. Breakthrough: Embracing Graph RAG and Cloud-Native
While exploring the open-source community, I identified a major pain point in traditional RAG: context fragmentation caused by chunking. **Graph RAG**, through "Entity-Relationship" modeling, provides a more robust solution for preserving complex relationships.

Consequently, I launched a new project: **[GraphWeaver](https://github.com/Suyw-0123/GraphWeaver)**.
This project is a culmination of my recent learning:
*   **High-Performance Backend**: Re-architected using **Golang (Gin)**.
*   **Cloud-Native Practice**: Integrated with **Kubernetes (K8s)** for microservice management.
*   **Automation**: Explored **GitHub Actions** for CI/CD pipelines.

## 5. Future: Continuous Growth in the Open Source Community
The path of technology is endless. Moving forward, I will dedicate more time to researching outstanding open-source projects such as:
*   **DeepTutor**: Its powerful system integration aligns closely with my project goals.
*   **LightRAG & KAG**: Exploring lighter yet higher-level knowledge-oriented architectures.
*   **Agentic RAG**: Studying how Agents can intelligently utilize RAG tools.

Beyond code, I’ve started actively participating in community discussions. Interacting with the open-source community has been incredibly rewarding and continues to motivate me to refine my projects.

---
*Post recorded on January 9, 2026. The development continues...*
