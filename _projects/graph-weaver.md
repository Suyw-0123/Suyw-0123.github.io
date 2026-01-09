---
layout: page
title: GraphWeaver
description: Graph RAG knowledge engine.
tags: ["Graph RAG", "Go", "React", "Kubernetes", "Neo4j"]
---

### [GitHub Repository](https://github.com/Suyw-0123/GraphWeaver)

## Project Overview

**GraphWeaver** is a cloud-native, high-performance **Graph RAG (Retrieval-Augmented Generation)** knowledge engine. It is designed to solve complex multi-hop reasoning challenges that traditional RAG systems struggle with by leveraging deep **Knowledge Graph** structures and entity-relationship modeling.

## Key Features

- **Knowledge Graph Retrieval**: Utilizes Graph Diffusion and relationship paths to perform logical reasoning across interconnected data points.
- **Cloud-Native Architecture**: Built as a microservice-based system, ready for Kubernetes (Kind/Helm) deployment.
- **High Performance**: Backend implemented in **Go (Golang)** for efficient concurrency and low-latency processing.
- **Automated Entity Extraction**: Automatically identifies and maps entities and relationships from unstructured data (PDF/Markdown).
- **Interactive Dashboard**: A modern, responsive UI built with **React**, **TypeScript**, and **Tailwind CSS**.

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

## DEMO

![demo](/pictures/graph-weaver-demo.gif)

## Development Status
This project is currently under active development, focusing on optimizing graph data fetching and enhancing the chat service implementation.
