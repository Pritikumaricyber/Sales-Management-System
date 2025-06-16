# 📦 Inventory Management System

## 📝 Project Overview

This project demonstrates the development of an **Inventory Management System** in **two levels**:

1. **Level 1: C++ Command-Line Version**  
2. **Level 2: Web-Based Version using HTML, CSS, and JavaScript**

The transition from a backend-focused console program to a fully interactive web interface shows how logic and UI can be developed and refined in stages.

---

## 🚀 Levels of Implementation

### 🔹 Level 1 – C++ (Command-Line)

A functional inventory tracker built using basic C++ features.

**Key Features:**
- Add new inventory items  
- Search for items  
- Sell (decrease quantity)  
- View all items  
- Save item details to a `.txt` file

**Skills Used:**
- OOP (Classes & Objects)  
- Vectors  
- File handling (using `fstream`)  
- Console-based user interaction

---

### 🔹 Level 2 – Frontend (HTML, CSS, JavaScript)

The logic is replicated and enhanced with a simple, clean UI – making inventory management easier and more visual.

**Key Features:**
- Add, search, sell, and display all items  
- Save inventory to a downloadable `.txt` file  
- Responsive layout using modern CSS  
- All logic handled using JavaScript in-browser (no backend)

> ⚠️ **Note:** The web version does **not** connect to the C++ backend. Data is handled using JavaScript only.

---

## 📁 Project Structure

```
inventory-management/
├── cli-version/
│   └── inventory.cpp
├── web-version/
│   ├── index.html
│   ├── style.css
│   └── script.js
└── README.md
```

---

## 🛠️ How to Use

### ✅ C++ Version

1. Open a terminal  
2. Compile and run:
   ```bash
   g++ inventory.cpp -o inventory
   ./inventory
   ```

---

### 🌐 Web Version

1. Open the `web-version/` folder  
2. Double-click or open `index.html` in your browser  
3. Use the interface to add, search, sell, and save items  

