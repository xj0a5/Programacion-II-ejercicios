# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'analizador_ejercicio2.ui'
##
## Created by: Qt User Interface Compiler version 6.12.0
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide6.QtCore import (QCoreApplication, QDate, QDateTime, QLocale,
    QMetaObject, QObject, QPoint, QRect,
    QSize, QTime, QUrl, Qt)
from PySide6.QtGui import (QBrush, QColor, QConicalGradient, QCursor,
    QFont, QFontDatabase, QGradient, QIcon,
    QImage, QKeySequence, QLinearGradient, QPainter,
    QPalette, QPixmap, QRadialGradient, QTransform)
from PySide6.QtWidgets import (QApplication, QGroupBox, QLabel, QMainWindow,
    QMenuBar, QPushButton, QSizePolicy, QStatusBar,
    QTextEdit, QWidget)

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        if not MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.resize(799, 600)
        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        self.widget = QWidget(self.centralwidget)
        self.widget.setObjectName(u"widget")
        self.widget.setGeometry(QRect(70, 90, 661, 461))
        self.widget.setStyleSheet(u"background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(0, 0, 0, 255), stop:0.05 rgba(14, 8, 73, 255), stop:0.36 rgba(28, 17, 145, 255), stop:0.6 rgba(126, 14, 81, 255), stop:0.75 rgba(234, 11, 11, 255), stop:0.79 rgba(244, 70, 5, 255), stop:0.86 rgba(255, 136, 0, 255), stop:0.935 rgba(239, 236, 55, 255));")
        self.groupBox = QGroupBox(self.centralwidget)
        self.groupBox.setObjectName(u"groupBox")
        self.groupBox.setEnabled(True)
        self.groupBox.setGeometry(QRect(70, -1, 661, 91))
        self.groupBox.setStyleSheet(u"background-color: rgb(239, 236, 55);")
        self.label = QLabel(self.groupBox)
        self.label.setObjectName(u"label")
        self.label.setGeometry(QRect(360, 20, 31, 16))
        self.label_2 = QLabel(self.groupBox)
        self.label_2.setObjectName(u"label_2")
        self.label_2.setGeometry(QRect(10, 20, 211, 16))
        self.textEdit_SNR = QTextEdit(self.groupBox)
        self.textEdit_SNR.setObjectName(u"textEdit_SNR")
        self.textEdit_SNR.setGeometry(QRect(390, 30, 171, 21))
        self.textEdit_SNR.setStyleSheet(u"background-color: rgb(235, 232, 77);\n"
"color:rgb(0, 0, 0);")
        self.pushButton_Actualizar = QPushButton(self.groupBox)
        self.pushButton_Actualizar.setObjectName(u"pushButton_Actualizar")
        self.pushButton_Actualizar.setGeometry(QRect(80, 60, 461, 23))
        self.pushButton_Actualizar.setStyleSheet(u"background-color: rgb(235, 232, 77);\n"
"color: rgb(0, 0, 0);")
        self.label_3 = QLabel(self.groupBox)
        self.label_3.setObjectName(u"label_3")
        self.label_3.setGeometry(QRect(10, 40, 111, 16))
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QMenuBar(MainWindow)
        self.menubar.setObjectName(u"menubar")
        self.menubar.setGeometry(QRect(0, 0, 799, 20))
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QStatusBar(MainWindow)
        self.statusbar.setObjectName(u"statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)

        QMetaObject.connectSlotsByName(MainWindow)
    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"MainWindow", None))
        self.groupBox.setTitle(QCoreApplication.translate("MainWindow", u"Parametros de Se\u00f1al", None))
        self.label.setText(QCoreApplication.translate("MainWindow", u"SNR", None))
        self.label_2.setText(QCoreApplication.translate("MainWindow", u"Frecuencia de muestreo[Hz]=8000", None))
        self.pushButton_Actualizar.setText(QCoreApplication.translate("MainWindow", u"Actualizar Gr\u00e1fico", None))
        self.label_3.setText(QCoreApplication.translate("MainWindow", u"Tono en 1Khz", None))
    # retranslateUi

