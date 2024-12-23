# Token Management System

**Tags**: `C++ Project` | `DSA Project`

---
This is a C++ project that implements a Token Management System using Data Structures and Algorithms (DSA) concepts. The project includes functionalities such as token issuance, counter management, and history tracking, utilizing queues, linked lists, and file handling.

## 📝 Project Overview

The Token Management System is a console-based **Data Structures and Algorithms (DSA)** project implemented in **C++**. It demonstrates the use of **Queues**, **Classes**, and various utility functions to manage tokens in a counter-based system.

---

## 🚀 Features

- Token issuance and management
- Waiting list implementation using a queue
- Real-time timestamp recording
- Console-based interactive UI with visual effects
- Utility functions like custom colors, delays, and sound effects
- File-based logging for token history

---

## 🛠️ Technologies Used

- Programming Language: **C++**
- Libraries: `<iostream>`, `<ctime>`, `<Windows.h>`, `<fstream>`

---

## 📁 File Structure
```plaintext
📂 Token Management System
├── main.cpp      # Contains the implementation code
├── file.txt      # Stores token issuance logs
└── README.md     # This documentation file
```

## Features
- **Token Issuance**: Automatically generates a token with a timestamp.
- **Queue Management**: Implements queue functionalities to maintain the waiting list.
- **Counter Operations**: Tracks and updates the counter's status (occupied or free).
- **History Tracking**: Logs issued tokens with timestamps into a file for record-keeping.
- **Custom UI Effects**: Features a colorful splash screen, help menu, and sound effects for an interactive experience.

## Technologies Used
- **Programming Language**: C++
- **Libraries**:
  - `<iostream>` for input/output operations.
  - `<ctime>` and `<time.h>` for time management.
  - `<Windows.h>` for console manipulation and sound effects.
  - `<fstream>` for file handling.
  - `<string>` for string operations.

## Code Overview
The project is divided into multiple classes and utility functions:
- **Counter Class**:
  - Tracks the counter status and the number of processed tokens.
- **Node Class**:
  - Represents a single token with its timestamp.
- **List Class**:
  - Implements queue functionalities such as `Enque`, `Deque`, and `isEmpty`.
- **Utility Functions**:
  - `splash()`: Displays a colorful splash screen.
  - `Help()`: Displays instructions for using the system.
  - `gotoXY()`: Positions text in the console window.
  - `setcolor()`: Changes the console text color.

## 📌 How to Run
1. Clone the repository:
   ```bash
   git clone https://github.com/iimranirshad/Token-Management-System.git
   ```
2. Compile the code using any C++ compiler:
   ```bash
   g++ TokenManagementSystem.cpp -o TokenManagementSystem
   ```
3. Run the program:
   ```bash
   ./TokenManagementSystem
   ```

---

## 🖼️ Demo

Add screenshots or GIFs here to show the application in action.

---



## 🎯 Key Concepts

- **Data Structures**:
  - Queue for managing tokens
  - Linked List for maintaining the waiting list
- **Algorithms**:
  - Enqueue and Dequeue operations
  - Time complexity: O(1) for enqueue/dequeue
- **File Handling**:
  - Logging token issuance with timestamps

---

## 📢 Tags

`C++ Project` | `DSA Project` | `Queue Implementation` | `File Handling`

---

## 🔗 License

This project is licensed under the MIT License. See the `LICENSE` file for more details.

---

## ✨ Credits

Developed by **Imran Irshad**.

## Acknowledgments
This project was developed by **Imran Irshad** as a demonstration of C++ and DSA skills. For further inquiries or contributions, feel free to contact me or raise an issue in this repository.

✉️imranirshad002@gmail.com
