Here is a **README.md** file for your installation script:

---

### **📄 README.md**
```md
# Qt WebEngine & Multimedia Dependencies Installation Script

This script installs all necessary dependencies for **Qt WebEngine** and **Qt Multimedia with RTSP support** on Ubuntu.

## **🔹 Features**
- Installs **Qt5 core libraries** (without `qmake`)
- Installs **CMake** for building Qt projects
- Installs **GStreamer** for RTSP streaming support
- Installs **Qt WebEngine** for rendering websites in Qt applications

## **📌 Prerequisites**
- You need a **Debian-based Linux system (Ubuntu 20.04+/Debian 10+)**
- Ensure you have `sudo` privileges

## **💻 Installation**
### **Step 1: Download the Script**
Clone this repository or download the script manually:
```bash
wget https://your-repository-url/install_qt_dependencies.sh
```

### **Step 2: Give Execution Permission**
```bash
chmod +x install_qt_dependencies.sh
```

### **Step 3: Run the Script**
```bash
./install_qt_dependencies.sh
```

## **📦 What This Script Installs**
| Dependency | Purpose |
|------------|---------|
| **cmake** | Used for building the Qt project |
| **qtbase5-dev** | Core Qt libraries |
| **qtchooser** | Helps choose Qt versions |
| **qtmultimedia5-dev** | Enables multimedia support in Qt |
| **GStreamer plugins** | Required for RTSP support |
| **qtwebengine5-dev** | Enables web rendering in Qt |

## **✅ Verification**
After installation, you can check if Qt WebEngine is installed by running:
```bash
dpkg -l | grep qtwebengine
```
```
