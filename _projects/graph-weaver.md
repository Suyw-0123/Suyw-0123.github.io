---
layout: page
title: GraphWeaver
description: Graph RAG knowledge engine.
tags: ["Graph RAG", "Go", "React", "Kubernetes", "Neo4j"]
---

### [GitHub Repository](https://github.com/Suyw-0123/GraphWeaver)

## Project Overview

**GraphWeaver** is a high-performance **Graph RAG (Retrieval-Augmented Generation)** knowledge engine. It leverages the power of "Entity-Relationship" modeling and "Semantic Vector" search to solve complex multi-hop reasoning challenges that traditional RAG systems often struggle with.

### DEMO

![demo](/pictures/graph-weaver-demo.gif)

## Key Features

- **Hybrid Retrieval Engine**: Combines **Vector Search** (for semantic entry points) with **Graph Diffusion** (for logical relationship reasoning).
- **Containerized Deployment**: Easy setup with **Docker Compose** for local development and testing.
- **High Performance**: Backend implemented in **Go (Golang)** for efficient concurrency and low-latency processing.
- **Modern Knowledge Management**: Automated entity and relationship extraction from unstructured data (PDF/Markdown).
- **Interactive UI**: Sleek and responsive dashboard built with **React**, **TypeScript**, and **Tailwind CSS**.

## System Architecture

![diagram](/pictures/graphweaver_architecture.png)

## Technology Stack

### Backend & Core
- **Language**: Go (Golang) 1.24+
- **Framework**: Gin Gonic
- **LLM Integration**: Gemini API

### Databases & Storage
- **Graph Database**: Neo4j (Core storage for relationship modeling)
- **Relational Database**: PostgreSQL (For metadata management)
- **Vector Search**: Qdrant (Planned for future hybrid retrieval implementation)

### Frontend & Styling 
- **Framework**: React.js with TypeScript
- **Styling**: Tailwind CSS
> The front-end was primarily completed with the assistance of Vibe coding.

### Infrastructure & DevOps
- **Containerization**: Docker & Docker Compose
- **Orchestration**: Kubernetes (K8s)
- **CI/CD**: GitHub Actions

## Development Status
This project is currently under active development, Currently, we're deploying using Docker Compose; the Kubernetes solution might require more time for me to research, now focusing on optimizing graph data fetching and enhancing the chat service implementation.
