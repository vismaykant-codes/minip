# 📁 File Management System (C Language)

## 🔹 Overview

This is a **menu-driven File Management System** implemented in C.
It allows users to perform basic file operations such as:

* Adding a file
* Deleting a file
* Sorting files
* Searching files

The program uses **structures, arrays, and standard C functions** to manage file data in memory.

---

## 🔹 Features

* 📌 Add new file records
* 🗑️ Delete existing files
* 🔍 Search files by name
* 🔄 Sort files by:

  * Name (Alphabetical)
  * Size (Ascending)
* 🖥️ Simple console-based UI with colors

---

## 🔹 Technologies Used

* C Programming Language
* Standard Libraries:

  * `stdio.h`
  * `stdlib.h`
  * `string.h`
  * `windows.h`
  * `conio.h`

---

## 🔹 Data Structure Used

```c
struct File {
    char name[50];
    int size;
    char date[20];
    char createdBy[30];
};
```

Each file stores:

* Name
* Size (in KB)
* Date
* Creator name

---

## 🔹 How It Works

1. The program starts with a **dashboard menu**
2. User selects an option (1–5)
3. Based on input:

   * Calls respective function
4. Runs continuously using an **infinite loop**
5. Stops only when user selects **Exit**

---

## 🔹 Menu Options

```
1. Add File
2. Delete File
3. Sort Files
4. Search File
5. Exit
```

---

## 🔹 Algorithms Used

* 🔍 **Linear Search** → for searching files
* 🔄 **Bubble Sort** → for sorting files

---

## 🔹 Limitations

* Stores data only in **temporary memory (RAM)**
* Maximum files limited to **50**
* Works only on **Windows (due to windows.h & conio.h)**

---

## 🔹 Possible Improvements

* 💾 Add file handling (save data permanently)
* 🔤 Case-insensitive search
* 📊 Better UI formatting
* ⬇️ Add descending sort option
* 🌐 Make it cross-platform (remove `conio.h`, `windows.h`)

---

## 🔹 How to Run

1. Compile using a C compiler (e.g., GCC / Turbo C)
2. Run the executable file
3. Use menu options to perform operations

---

## 🔹 Example

```
Enter your choice: 1
→ Add file details

Enter your choice: 4
→ Search file
```

---

## 🔹 Author

* Developed as a **basic C programming project** for learning:

  * Structures
  * Arrays
  * Searching & Sorting
  * Menu-driven programs

---

## 🔹 Conclusion

This project demonstrates core C programming concepts and provides a simple simulation of file management operations in a console environment.
