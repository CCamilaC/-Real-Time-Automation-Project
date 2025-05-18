# Real-Time Automation Final Project – ELT127
This project involves creating a multithreaded application to monitor railway safety in real time by detecting overheated train wheels. Data from sensors and remote I/O stations is sent to PLCs and processed at the control center to prevent derailments.


## Project Overview

The goal of this project is to design and implement a **real-time, multithreaded software application** that simulates the monitoring and control of a **railway system**, focusing on safety through the **detection of overheated train wheels (hot wheels)** and monitoring of **railway signaling devices**.

A **railway company** has added a new segment to its rail network, equipped with **remote I/O stations** and **hot wheel detectors (hotboxes)**. These devices send field data to **Programmable Logic Controllers (PLCs)**, which forward the information to the **Operations Control Center (CCO)**.

The application must:
- Simulate **data acquisition** from PLCs.
- Store and process information using shared memory and file-based mechanisms.
- Display alerts and operational statuses in two separate console terminals:
  - One for general **railway signaling**.
  - One for **hot wheel and hardware failure alerts**.

---

## System Tasks

### 1. PLC Reading Task
- Simulates reading from PLCs.
- Generates:
  - Signaling messages (interval: 100–2000 ms, random).
  - Hotbox messages (interval: every 500 ms).
- Stores messages in a shared **circular buffer in RAM**.
- If the buffer is full, the task blocks and displays a warning.

### 2. Signaling Data Capture Task
- Consumes signaling messages from the buffer.
- If `DIAG = 1` (hardware failure), forwards the message to the hot wheel display.
- Otherwise, stores messages in a **circular file on disk** (max: 200 messages).
- If the disk file is full, blocks and alerts the user.

### 3. Hotbox Data Capture Task
- Consumes hotbox messages from the buffer.
- Forwards them to the hot wheel display.

### 4. Signaling Display Task
- Reads messages from the disk file.
- Displays signaling information in a console.
- Must include **at least 20 different signaling states** (e.g., "Switch Activated", "Signal at STOP").

### 5. Hot Wheel Display Task
- Receives messages from:
  - Signaling data capture (on hardware failure).
  - Hotbox data capture.
- Displays alerts in a **dedicated console**.

### 6. Keyboard Input Task
- Monitors for operator input:
  - `'c'`: toggle PLC reading task.
  - `'d'`: toggle signaling data capture.
  - `'h'`: toggle hotbox data capture.
  - `'s'`: toggle signaling display.
  - `'q'`: toggle hot wheel display.
  - `ESC`: shuts down the entire system.

---

## Project Phases

### Phase 1 – Basic Architecture
- Design the multithreaded/process structure.
- Implement the **in-memory circular buffer**.
- Use `Sleep()` for provisional timing.
- Handle **task synchronization** and control using event objects.
- Perform initial testing and debugging.

### Phase 2 – Final Integration
- Replace `Sleep()` with proper timers (excluding `Sleep()`).
- Implement:
  - **Disk-based circular file**.
  - **Inter-process communication (IPC)** via pipes or mailslots.
  - Full console display for signaling and hot wheels.
- Perform final integration and complete system testing.

---

## Technical Requirements

- Language: **C++**
- IDE: **Microsoft Visual Studio Community Edition**
- Structure: One solution with **separate projects** (executables) under a single launcher.
- Use **relative paths** in all file references.
- Submit via **Moodle**:
  - Source code (zipped Visual Studio solution).
  - PDF with:
    - Names of authors.
    - Explanation of architecture, task responsibilities, synchronization, test results, and relevant observations.

---

## Bonus Points (Up to +5)

- Use of **Pthreads-Win32** for threading and synchronization (with proper setup).
- Additional useful features, clearly documented.
- High-quality documentation and code organization.

---

Let me know if you want this in `.md` file format or translated to Portuguese.
