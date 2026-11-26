# 📇 Contact Directory Management System (DSA in C)

![Language](https://img.shields.io/badge/Language-C%20(C99)-blue.svg)
![DSA](https://img.shields.io/badge/DSA-Singly%20Linked%20List%20%7C%20Searching%20%7C%20Sorting-brightgreen.svg)
![Build](https://img.shields.io/badge/Compiler-GCC%20%2F%20MinGW-orange.svg)
![Course](https://img.shields.io/badge/Course-B.Tech%20CSE%20(IoT)%20%E2%80%94%20DSA%20Lab-purple.svg)

A clean, single-file, menu-driven **Contact Directory Management System** implemented in **C** using a **Singly Linked List**, dynamic heap memory allocation (`malloc` / `free`), **Linear Search Traversal**, **Pairwise Duplicate Detection**, and **In-Place Bubble Sort**.

Developed as a Data Structures and Algorithms (DSA) Laboratory Project at **Global Institute of Technology, Jaipur**.

---

## 📑 Table of Contents

- [Project Overview](#-project-overview)
- [Core Data Structure](#-core-data-structure)
- [Features & Modules](#-features--modules)
- [Function Reference](#-function-reference)
- [Time & Space Complexity Analysis](#-time--space-complexity-analysis)
- [Getting Started](#-getting-started)
- [Menu Options](#-menu-options)
- [Sample Program Output](#-sample-program-output)
- [Repository Structure](#-repository-structure)
- [Author & Academic Details](#-author--academic-details)

---

## 🎯 Project Overview

Managing contacts in a static fixed-size array enforces rigid capacity limits and requires costly $O(N)$ memory shifting on arbitrary insertions and deletions. This project models a real-world digital contact directory using a **Singly Linked List** (`main.c`, 512 lines) where every contact lives in dynamically allocated heap memory and links sequentially to the next record.

Key design goals:
- **Zero wasted memory:** Nodes are allocated strictly on demand using `malloc()` and released safely using `free()`.
- **Single-file portability:** Compiles cleanly with any standard C compiler (`gcc`) with zero external dependencies (`stdio.h`, `stdlib.h`, `string.h`).
- **Clear DSA implementation:** Every core operation—insertion, deletion, traversal, search, duplicate checking, and sorting—is written explicitly using linked list pointers.

---

## 🧱 Core Data Structure

Each contact record is stored as a self-referential `struct Contact` node, tracked globally from `head`:

```c
struct Contact {
    char name[50];
    char phone[20];
    char email[50];
    struct Contact *next;
};

struct Contact *head = NULL;
```

```
head ──▶ [ Name | Phone | Email | next ] ──▶ [ Name | Phone | Email | next ] ──▶ NULL
```

---

## ✨ Features & Modules

### 1️⃣ Module 1: Add and Insert Contact Module
- **Insert at Beginning (`insertBeginning`)**: Prepends a new contact directly to `head` in $O(1)$ time without traversing the list.
- **Insert at End (`insertEnd`)**: Traverses to the tail node (`temp->next == NULL`) and appends the new contact node.
- **Insert at Specific Position (`insertAtPosition`)**: Inserts a contact at any valid 1-based position `pos` (`1, 2, 3...`), with automatic validation for `pos < 1`, `pos == 1` (delegated to `insertBeginning`), and out-of-range positions.

### 2️⃣ Module 2: Delete and Update Module
- **Delete by Name (`deleteByName`)**: Locates the first node whose `name` matches via `strcmp()`, handles both head-node and internal/tail-node unlinking, and releases memory with `free()`.
- **Delete by Phone Number (`deleteByPhone`)**: Locates and removes a contact node by exact `phone` match and frees heap memory.
- **Update Contact Details (`updateContact`)**: Traverses the list to match either `name` or `phone` against the user's query, then edits `name`, `phone`, and `email` in-place without recreating nodes.

### 3️⃣ Module 3: Search Module (Traversal)
- **Search by Name (`searchByName`)**: Performs linear traversal from `head` to `NULL` and prints all matching contacts.
- **Search by Phone (`searchByPhone`)**: Traverses sequentially and returns immediately on an exact phone number match.
- **Search by Email (`searchByEmail`)**: Traverses the list and displays all contacts matching the specified email address.

### 4️⃣ Module 4: Display and Duplicate Check Module
- **Display All Contacts (`displayContacts`)**: Prints all stored contacts in an aligned tabular layout (`No.`, `Name`, `Phone`, `Email`) along with the total contact count.
- **Count Total Contacts (`countContacts`)**: Traverses the linked list and reports the total number of active nodes.
- **Detect Duplicates (`detectDuplicates`)**: Uses nested pairwise pointer traversal (`i = head`, `j = i->next`) to flag any two contacts sharing an identical phone number or email address.
- **Show Contacts Alphabetically (`sortAlphabetical`)**: Implements **Bubble Sort on the Linked List**, comparing adjacent node names lexicographically (`strcmp(i->name, j->name) > 0`), swapping their `name`, `phone`, and `email` strings via `strcpy()`, and calling `displayContacts()` to display the sorted A–Z directory.

---

## 🛠️ Function Reference

| Function | Module | Description |
| :--- | :---: | :--- |
| `addContactMenu()` | Module 1 | Collects Name, Phone, Email and routes to Beginning, End, or Position insertion |
| `insertBeginning()` | Module 1 | Inserts newly allocated `struct Contact` node at list head |
| `insertEnd()` | Module 1 | Appends newly allocated node to list tail |
| `insertAtPosition()` | Module 1 | Inserts node at specified 1-based position with boundary checks |
| `deleteMenu()` | Module 2 | Menu to choose deletion by Name or Phone Number |
| `deleteByName()` | Module 2 | Unlinks and frees node matching given name |
| `deleteByPhone()` | Module 2 | Unlinks and frees node matching given phone number |
| `updateContact()` | Module 2 | Searches by Name/Phone and modifies contact fields in-place |
| `searchMenu()` | Module 3 | Menu to choose searching by Name, Phone, or Email |
| `searchByName()` | Module 3 | Linear traversal matching `name` via `strcmp()` |
| `searchByPhone()` | Module 3 | Linear traversal matching `phone` via `strcmp()` |
| `searchByEmail()` | Module 3 | Linear traversal matching `email` via `strcmp()` |
| `displayContacts()` | Module 4 | Prints all contacts in aligned tabular columns with total count |
| `countContacts()` | Module 4 | Counts total nodes in the linked list |
| `detectDuplicates()` | Module 4 | Checks all unordered pairs `(i, j)` for duplicate phone or email |
| `sortAlphabetical()` | Module 4 | Sorts directory A–Z via Bubble Sort and displays the sorted list |

---

## ⏱️ Time & Space Complexity Analysis

Let $N$ be the number of contacts currently stored in the linked list:

| Operation | Best Case | Average / Worst Case | Auxiliary Space |
| :--- | :---: | :---: | :---: |
| **Insert at Beginning** | $O(1)$ | $O(1)$ | $O(1)$ |
| **Insert at End / Position** | $O(1)$ | $O(N)$ | $O(1)$ |
| **Delete by Name / Phone** | $O(1)$ | $O(N)$ | $O(1)$ |
| **Update Contact** | $O(1)$ | $O(N)$ | $O(1)$ |
| **Search (Name / Phone / Email)** | $O(1)$ | $O(N)$ | $O(1)$ |
| **Display / Count Contacts** | $O(N)$ | $O(N)$ | $O(1)$ |
| **Duplicate Detection** | $O(N^2)$ | $O(N^2)$ | $O(1)$ |
| **Alphabetical Bubble Sort** | $O(N^2)$ | $O(N^2)$ | $O(1)$ |
| **Total Storage Space** | — | — | $O(N)$ |

---

## 🚀 Getting Started

### Prerequisites
- A C compiler such as **GCC** (MinGW on Windows, GCC on Linux, or Clang on macOS).

### Option 1: One-Click Run (Windows)
Double-click **`run.bat`**, which compiles `main.c` with strict C99 flags and launches `contact_directory.exe`:
```bat
gcc -std=c99 -Wall -Wextra main.c -o contact_directory.exe
contact_directory.exe
```

### Option 2: Compile & Run Manually via Terminal

**Windows (PowerShell / CMD):**
```powershell
gcc -std=c99 -Wall -Wextra main.c -o contact_directory.exe
.\contact_directory.exe
```

**Linux / macOS:**
```bash
gcc -std=c99 -Wall -Wextra main.c -o contact_directory
./contact_directory
```

---

## 📋 Menu Options

```text
===== CONTACT DIRECTORY MANAGEMENT SYSTEM =====
1. Add / Insert Contact
2. Delete Contact
3. Update Contact
4. Search Contact
5. Display All Contacts
6. Count Total Contacts
7. Detect Duplicates
8. Show Contacts Alphabetically
0. Exit
Enter your choice:
```

---

## 💻 Sample Program Output

```text
===== CONTACT DIRECTORY MANAGEMENT SYSTEM =====
1. Add / Insert Contact
2. Delete Contact
3. Update Contact
4. Search Contact
5. Display All Contacts
6. Count Total Contacts
7. Detect Duplicates
8. Show Contacts Alphabetically
0. Exit
Enter your choice: 5

No.   Name                 Phone           Email                    
--------------------------------------------------------------------
1     Sourabh Dhara        9876543210      sourabh@mail.com         
2     Bob Smith            9876543210      bob@mail.com             
3     Alice Johnson        9123456789      alice@mail.com           
--------------------------------------------------------------------
Total Contacts: 3

Enter your choice: 7

Checking for duplicates...
[Duplicate Phone Found]
  Contact 1: Sourabh Dhara (9876543210)
  Contact 2: Bob Smith (9876543210)

Enter your choice: 8

Contacts sorted in alphabetical order successfully!

No.   Name                 Phone           Email                    
--------------------------------------------------------------------
1     Alice Johnson        9123456789      alice@mail.com           
2     Bob Smith            9876543210      bob@mail.com             
3     Sourabh Dhara        9876543210      sourabh@mail.com         
--------------------------------------------------------------------
Total Contacts: 3
```

---

## 📂 Repository Structure

```text
Contact-Directory-Management-System/
├── main.c                                                    # Complete single-file C implementation
├── run.bat                                                   # Windows build & launch script
├── GITHUB_README.md                                          # Detailed GitHub documentation
├── README.md                                                 # Concise viva explanation guide
└── ContactDirectory_LabFile_ContinuousFlow.docx              # DSA Lab Project Report (GIT Format)
```

---

## 🎓 Author & Academic Details

- **Student Name:** Sourabh Dhara
- **RTU Roll No.:** `25EGJCY025`
- **Branch:** B.Tech — Computer Science and Engineering (IoT), III Semester (II Year)
- **Institution:** Global Institute of Technology, Jaipur (Rajasthan) – 302022
- **Lab Subject:** Data Structures and Algorithms Lab (Session 2026–27)
- **Faculty Guide:** Mr. Chandrabhan Mishra Sir, Assistant Professor, Department of CSE
