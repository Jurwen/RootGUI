/********************************************************************************
** Form generated from reading UI file 'mainPage.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPAGE_H
#define UI_MAINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "glarea.h"

QT_BEGIN_NAMESPACE

class Ui_mainPageClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_81;
    glArea *openGLWidget;
    QHBoxLayout *glLayout;
    QTabWidget *tabWidget;
    QWidget *skeletonTab;
    QCheckBox *showSkel;
    QSlider *skelWidthSlider;
    QLabel *label_2;
    QDoubleSpinBox *jetMinBox;
    QDoubleSpinBox *jetMaxBox;
    QPushButton *skelFileBrowseBtn;
    QLineEdit *skelFileLabel;
    QCheckBox *whorlAbove;
    QCheckBox *showPlane;
    QCheckBox *showLvl0Root;
    QCheckBox *showLvl1Root;
    QCheckBox *showLvl2Root;
    QCheckBox *showLvl3Root;
    QCheckBox *showLvlLaterRoot;
    QCheckBox *whorlBelow;
    QCheckBox *nodalRootAbove;
    QCheckBox *nodalRootBelow;
    QLineEdit *annotationFileLabel;
    QPushButton *annotationFileBrowseBtn;
    QComboBox *skeletonColor;
    QLabel *label_7;
    QLabel *label_8;
    QCheckBox *nodalRootsbyWhorls;
    QWidget *meshTab;
    QCheckBox *showMesh;
    QSlider *alphaSlider;
    QLabel *label;
    QSlider *meshColorRedSlider;
    QSlider *meshColorGreenSlider;
    QSlider *meshColorBlueSlider;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *meshFileLabel;
    QPushButton *meshFileBrowseBtn;
    QLineEdit *meshFileLabel_obj;
    QPushButton *meshFileBrowseBtn_obj;
    QSlider *backColorRedSlider;
    QSlider *backColorBlueSlider;
    QSlider *backColorGreenSlider;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QWidget *editTab;
    QTextEdit *inputTextChi;
    QPushButton *verifyTop;
    QSlider *planeAdjustor;
    QPushButton *inputValuePar;
    QPushButton *swapLast;
    QTextEdit *whorlDelete;
    QTextEdit *inputTextPar;
    QCheckBox *editWhorlOn;
    QPushButton *addWhorl;
    QCheckBox *editOn;
    QPushButton *deleteWhorlConf;
    QPushButton *verifyBot;
    QTextEdit *inputTextBot;
    QPushButton *inputValueChi;
    QTextEdit *inputTextTop;
    QSpacerItem *horizontalSpacer_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *mainPageClass)
    {
        if (mainPageClass->objectName().isEmpty())
            mainPageClass->setObjectName(QStringLiteral("mainPageClass"));
        mainPageClass->resize(924, 851);
        centralWidget = new QWidget(mainPageClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_81 = new QGridLayout(centralWidget);
        gridLayout_81->setSpacing(6);
        gridLayout_81->setContentsMargins(11, 11, 11, 11);
        gridLayout_81->setObjectName(QStringLiteral("gridLayout_81"));
        openGLWidget = new glArea(centralWidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));

        gridLayout_81->addWidget(openGLWidget, 0, 1, 1, 1);

        glLayout = new QHBoxLayout();
        glLayout->setSpacing(6);
        glLayout->setObjectName(QStringLiteral("glLayout"));
        glLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMaximumSize(QSize(200, 16777215));
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        tabWidget->setFont(font);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setStyleSheet(QLatin1String("QTabWidget{\n"
"	background-color: #C0C0C0;\n"
"	border: 1 px solid gray;\n"
"}"));
        skeletonTab = new QWidget();
        skeletonTab->setObjectName(QStringLiteral("skeletonTab"));
        skeletonTab->setStyleSheet(QLatin1String("QTabWidget{\n"
"	background-color: #C0C0C0;\n"
"	border: 1 px solid gray;\n"
"}"));
        showSkel = new QCheckBox(skeletonTab);
        showSkel->setObjectName(QStringLiteral("showSkel"));
        showSkel->setGeometry(QRect(20, 10, 131, 21));
        showSkel->setChecked(true);
        skelWidthSlider = new QSlider(skeletonTab);
        skelWidthSlider->setObjectName(QStringLiteral("skelWidthSlider"));
        skelWidthSlider->setGeometry(QRect(20, 90, 141, 22));
        skelWidthSlider->setValue(81);
        skelWidthSlider->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(skeletonTab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 110, 111, 31));
        jetMinBox = new QDoubleSpinBox(skeletonTab);
        jetMinBox->setObjectName(QStringLiteral("jetMinBox"));
        jetMinBox->setGeometry(QRect(10, 190, 62, 22));
        jetMaxBox = new QDoubleSpinBox(skeletonTab);
        jetMaxBox->setObjectName(QStringLiteral("jetMaxBox"));
        jetMaxBox->setGeometry(QRect(90, 190, 62, 22));
        jetMaxBox->setValue(5);
        skelFileBrowseBtn = new QPushButton(skeletonTab);
        skelFileBrowseBtn->setObjectName(QStringLiteral("skelFileBrowseBtn"));
        skelFileBrowseBtn->setGeometry(QRect(90, 40, 75, 23));
        skelFileLabel = new QLineEdit(skeletonTab);
        skelFileLabel->setObjectName(QStringLiteral("skelFileLabel"));
        skelFileLabel->setGeometry(QRect(10, 40, 71, 20));
        whorlAbove = new QCheckBox(skeletonTab);
        whorlAbove->setObjectName(QStringLiteral("whorlAbove"));
        whorlAbove->setGeometry(QRect(10, 440, 151, 31));
        whorlAbove->setChecked(false);
        showPlane = new QCheckBox(skeletonTab);
        showPlane->setObjectName(QStringLiteral("showPlane"));
        showPlane->setGeometry(QRect(10, 410, 151, 31));
        showPlane->setChecked(false);
        showLvl0Root = new QCheckBox(skeletonTab);
        showLvl0Root->setObjectName(QStringLiteral("showLvl0Root"));
        showLvl0Root->setGeometry(QRect(10, 260, 151, 31));
        showLvl0Root->setChecked(true);
        showLvl1Root = new QCheckBox(skeletonTab);
        showLvl1Root->setObjectName(QStringLiteral("showLvl1Root"));
        showLvl1Root->setGeometry(QRect(10, 290, 151, 31));
        showLvl1Root->setChecked(true);
        showLvl2Root = new QCheckBox(skeletonTab);
        showLvl2Root->setObjectName(QStringLiteral("showLvl2Root"));
        showLvl2Root->setGeometry(QRect(10, 320, 151, 31));
        showLvl2Root->setChecked(true);
        showLvl3Root = new QCheckBox(skeletonTab);
        showLvl3Root->setObjectName(QStringLiteral("showLvl3Root"));
        showLvl3Root->setGeometry(QRect(10, 350, 151, 31));
        showLvl3Root->setChecked(true);
        showLvlLaterRoot = new QCheckBox(skeletonTab);
        showLvlLaterRoot->setObjectName(QStringLiteral("showLvlLaterRoot"));
        showLvlLaterRoot->setGeometry(QRect(10, 380, 151, 31));
        showLvlLaterRoot->setChecked(true);
        whorlBelow = new QCheckBox(skeletonTab);
        whorlBelow->setObjectName(QStringLiteral("whorlBelow"));
        whorlBelow->setGeometry(QRect(10, 470, 151, 31));
        whorlBelow->setChecked(false);
        nodalRootAbove = new QCheckBox(skeletonTab);
        nodalRootAbove->setObjectName(QStringLiteral("nodalRootAbove"));
        nodalRootAbove->setGeometry(QRect(10, 500, 151, 31));
        nodalRootAbove->setChecked(false);
        nodalRootBelow = new QCheckBox(skeletonTab);
        nodalRootBelow->setObjectName(QStringLiteral("nodalRootBelow"));
        nodalRootBelow->setGeometry(QRect(10, 530, 151, 31));
        nodalRootBelow->setChecked(false);
        annotationFileLabel = new QLineEdit(skeletonTab);
        annotationFileLabel->setObjectName(QStringLiteral("annotationFileLabel"));
        annotationFileLabel->setGeometry(QRect(10, 60, 71, 20));
        annotationFileBrowseBtn = new QPushButton(skeletonTab);
        annotationFileBrowseBtn->setObjectName(QStringLiteral("annotationFileBrowseBtn"));
        annotationFileBrowseBtn->setGeometry(QRect(90, 60, 75, 23));
        skeletonColor = new QComboBox(skeletonTab);
        skeletonColor->addItem(QString());
        skeletonColor->addItem(QString());
        skeletonColor->addItem(QString());
        skeletonColor->setObjectName(QStringLiteral("skeletonColor"));
        skeletonColor->setGeometry(QRect(10, 140, 141, 21));
        skeletonColor->setEditable(false);
        label_7 = new QLabel(skeletonTab);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 160, 111, 31));
        label_8 = new QLabel(skeletonTab);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 220, 111, 31));
        nodalRootsbyWhorls = new QCheckBox(skeletonTab);
        nodalRootsbyWhorls->setObjectName(QStringLiteral("nodalRootsbyWhorls"));
        nodalRootsbyWhorls->setGeometry(QRect(10, 560, 151, 31));
        nodalRootsbyWhorls->setChecked(false);
        tabWidget->addTab(skeletonTab, QString());
        meshTab = new QWidget();
        meshTab->setObjectName(QStringLiteral("meshTab"));
        meshTab->setStyleSheet(QLatin1String("QTabWidget{\n"
"	background-color: #C0C0C0;\n"
"	border: 1 px solid gray;\n"
"}"));
        showMesh = new QCheckBox(meshTab);
        showMesh->setObjectName(QStringLiteral("showMesh"));
        showMesh->setGeometry(QRect(30, 10, 131, 21));
        showMesh->setChecked(true);
        alphaSlider = new QSlider(meshTab);
        alphaSlider->setObjectName(QStringLiteral("alphaSlider"));
        alphaSlider->setGeometry(QRect(10, 90, 141, 22));
        alphaSlider->setValue(55);
        alphaSlider->setOrientation(Qt::Horizontal);
        label = new QLabel(meshTab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 110, 111, 31));
        meshColorRedSlider = new QSlider(meshTab);
        meshColorRedSlider->setObjectName(QStringLiteral("meshColorRedSlider"));
        meshColorRedSlider->setGeometry(QRect(20, 140, 141, 22));
        meshColorRedSlider->setValue(99);
        meshColorRedSlider->setOrientation(Qt::Horizontal);
        meshColorGreenSlider = new QSlider(meshTab);
        meshColorGreenSlider->setObjectName(QStringLiteral("meshColorGreenSlider"));
        meshColorGreenSlider->setGeometry(QRect(20, 160, 141, 22));
        meshColorGreenSlider->setValue(99);
        meshColorGreenSlider->setOrientation(Qt::Horizontal);
        meshColorBlueSlider = new QSlider(meshTab);
        meshColorBlueSlider->setObjectName(QStringLiteral("meshColorBlueSlider"));
        meshColorBlueSlider->setGeometry(QRect(20, 180, 141, 22));
        meshColorBlueSlider->setValue(99);
        meshColorBlueSlider->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(meshTab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 130, 16, 31));
        label_4 = new QLabel(meshTab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 150, 16, 31));
        label_5 = new QLabel(meshTab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 170, 16, 31));
        label_6 = new QLabel(meshTab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(70, 190, 41, 31));
        meshFileLabel = new QLineEdit(meshTab);
        meshFileLabel->setObjectName(QStringLiteral("meshFileLabel"));
        meshFileLabel->setGeometry(QRect(10, 30, 71, 20));
        meshFileBrowseBtn = new QPushButton(meshTab);
        meshFileBrowseBtn->setObjectName(QStringLiteral("meshFileBrowseBtn"));
        meshFileBrowseBtn->setGeometry(QRect(90, 30, 75, 23));
        meshFileLabel_obj = new QLineEdit(meshTab);
        meshFileLabel_obj->setObjectName(QStringLiteral("meshFileLabel_obj"));
        meshFileLabel_obj->setGeometry(QRect(10, 60, 71, 20));
        meshFileBrowseBtn_obj = new QPushButton(meshTab);
        meshFileBrowseBtn_obj->setObjectName(QStringLiteral("meshFileBrowseBtn_obj"));
        meshFileBrowseBtn_obj->setGeometry(QRect(90, 60, 75, 23));
        backColorRedSlider = new QSlider(meshTab);
        backColorRedSlider->setObjectName(QStringLiteral("backColorRedSlider"));
        backColorRedSlider->setGeometry(QRect(20, 230, 141, 22));
        backColorRedSlider->setValue(99);
        backColorRedSlider->setOrientation(Qt::Horizontal);
        backColorBlueSlider = new QSlider(meshTab);
        backColorBlueSlider->setObjectName(QStringLiteral("backColorBlueSlider"));
        backColorBlueSlider->setGeometry(QRect(20, 270, 141, 22));
        backColorBlueSlider->setValue(99);
        backColorBlueSlider->setOrientation(Qt::Horizontal);
        backColorGreenSlider = new QSlider(meshTab);
        backColorGreenSlider->setObjectName(QStringLiteral("backColorGreenSlider"));
        backColorGreenSlider->setGeometry(QRect(20, 250, 141, 22));
        backColorGreenSlider->setValue(99);
        backColorGreenSlider->setOrientation(Qt::Horizontal);
        label_9 = new QLabel(meshTab);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(50, 290, 101, 31));
        label_10 = new QLabel(meshTab);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 240, 16, 31));
        label_11 = new QLabel(meshTab);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 220, 16, 31));
        label_12 = new QLabel(meshTab);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 260, 16, 31));
        tabWidget->addTab(meshTab, QString());
        editTab = new QWidget();
        editTab->setObjectName(QStringLiteral("editTab"));
        inputTextChi = new QTextEdit(editTab);
        inputTextChi->setObjectName(QStringLiteral("inputTextChi"));
        inputTextChi->setGeometry(QRect(100, 40, 60, 31));
        verifyTop = new QPushButton(editTab);
        verifyTop->setObjectName(QStringLiteral("verifyTop"));
        verifyTop->setGeometry(QRect(70, 140, 31, 28));
        planeAdjustor = new QSlider(editTab);
        planeAdjustor->setObjectName(QStringLiteral("planeAdjustor"));
        planeAdjustor->setGeometry(QRect(20, 210, 141, 22));
        planeAdjustor->setValue(50);
        planeAdjustor->setOrientation(Qt::Horizontal);
        inputValuePar = new QPushButton(editTab);
        inputValuePar->setObjectName(QStringLiteral("inputValuePar"));
        inputValuePar->setGeometry(QRect(70, 40, 31, 28));
        swapLast = new QPushButton(editTab);
        swapLast->setObjectName(QStringLiteral("swapLast"));
        swapLast->setGeometry(QRect(110, 20, 61, 21));
        whorlDelete = new QTextEdit(editTab);
        whorlDelete->setObjectName(QStringLiteral("whorlDelete"));
        whorlDelete->setGeometry(QRect(10, 100, 104, 30));
        inputTextPar = new QTextEdit(editTab);
        inputTextPar->setObjectName(QStringLiteral("inputTextPar"));
        inputTextPar->setGeometry(QRect(10, 40, 61, 31));
        editWhorlOn = new QCheckBox(editTab);
        editWhorlOn->setObjectName(QStringLiteral("editWhorlOn"));
        editWhorlOn->setGeometry(QRect(10, 80, 91, 20));
        addWhorl = new QPushButton(editTab);
        addWhorl->setObjectName(QStringLiteral("addWhorl"));
        addWhorl->setGeometry(QRect(10, 180, 180, 21));
        editOn = new QCheckBox(editTab);
        editOn->setObjectName(QStringLiteral("editOn"));
        editOn->setGeometry(QRect(10, 20, 91, 20));
        deleteWhorlConf = new QPushButton(editTab);
        deleteWhorlConf->setObjectName(QStringLiteral("deleteWhorlConf"));
        deleteWhorlConf->setGeometry(QRect(120, 100, 60, 28));
        verifyBot = new QPushButton(editTab);
        verifyBot->setObjectName(QStringLiteral("verifyBot"));
        verifyBot->setGeometry(QRect(160, 140, 31, 28));
        inputTextBot = new QTextEdit(editTab);
        inputTextBot->setObjectName(QStringLiteral("inputTextBot"));
        inputTextBot->setGeometry(QRect(100, 140, 60, 31));
        inputValueChi = new QPushButton(editTab);
        inputValueChi->setObjectName(QStringLiteral("inputValueChi"));
        inputValueChi->setGeometry(QRect(160, 40, 31, 28));
        inputTextTop = new QTextEdit(editTab);
        inputTextTop->setObjectName(QStringLiteral("inputTextTop"));
        inputTextTop->setGeometry(QRect(10, 140, 60, 31));
        tabWidget->addTab(editTab, QString());

        glLayout->addWidget(tabWidget);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        glLayout->addItem(horizontalSpacer_2);


        gridLayout_81->addLayout(glLayout, 0, 0, 1, 1);

        mainPageClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(mainPageClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        mainPageClass->setStatusBar(statusBar);

        retranslateUi(mainPageClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(mainPageClass);
    } // setupUi

    void retranslateUi(QMainWindow *mainPageClass)
    {
        mainPageClass->setWindowTitle(QApplication::translate("mainPageClass", "Root Viwer", nullptr));
        showSkel->setText(QApplication::translate("mainPageClass", "Show Skeleton", nullptr));
        label_2->setText(QApplication::translate("mainPageClass", "Skeleton Width", nullptr));
        skelFileBrowseBtn->setText(QApplication::translate("mainPageClass", "Select .ply", nullptr));
        whorlAbove->setText(QApplication::translate("mainPageClass", "Show Whorls Above", nullptr));
        showPlane->setText(QApplication::translate("mainPageClass", "Show Soil Plane", nullptr));
        showLvl0Root->setText(QApplication::translate("mainPageClass", "Show Stem Path", nullptr));
        showLvl1Root->setText(QApplication::translate("mainPageClass", "Show Stem Region", nullptr));
        showLvl2Root->setText(QApplication::translate("mainPageClass", "Show Nodal Roots", nullptr));
        showLvl3Root->setText(QApplication::translate("mainPageClass", "Show Secondary Roots", nullptr));
        showLvlLaterRoot->setText(QApplication::translate("mainPageClass", "Show Other Roots", nullptr));
        whorlBelow->setText(QApplication::translate("mainPageClass", "Show Whorls Below", nullptr));
        nodalRootAbove->setText(QApplication::translate("mainPageClass", "Show Nodal Roots Above", nullptr));
        nodalRootBelow->setText(QApplication::translate("mainPageClass", "Show Nodal Roots Below", nullptr));
        annotationFileBrowseBtn->setText(QApplication::translate("mainPageClass", "Select .txt", nullptr));
        skeletonColor->setItemText(0, QApplication::translate("mainPageClass", "Normal Coloring(Black)", nullptr));
        skeletonColor->setItemText(1, QApplication::translate("mainPageClass", "Color by Hierarchy", nullptr));
        skeletonColor->setItemText(2, QApplication::translate("mainPageClass", "Color by Radius", nullptr));

        label_7->setText(QApplication::translate("mainPageClass", "Skeleton Color", nullptr));
        label_8->setText(QApplication::translate("mainPageClass", "Skeleton Color Range", nullptr));
        nodalRootsbyWhorls->setText(QApplication::translate("mainPageClass", "Show Nodal Roots by Whorls", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(skeletonTab), QApplication::translate("mainPageClass", "Skeleton", nullptr));
        showMesh->setText(QApplication::translate("mainPageClass", "Show Mesh", nullptr));
        label->setText(QApplication::translate("mainPageClass", "Transparency", nullptr));
        label_3->setText(QApplication::translate("mainPageClass", "R", nullptr));
        label_4->setText(QApplication::translate("mainPageClass", "G", nullptr));
        label_5->setText(QApplication::translate("mainPageClass", "B", nullptr));
        label_6->setText(QApplication::translate("mainPageClass", "Color", nullptr));
        meshFileBrowseBtn->setText(QApplication::translate("mainPageClass", "Select .off", nullptr));
        meshFileBrowseBtn_obj->setText(QApplication::translate("mainPageClass", "Select .obj", nullptr));
        label_9->setText(QApplication::translate("mainPageClass", "Background Color", nullptr));
        label_10->setText(QApplication::translate("mainPageClass", "G", nullptr));
        label_11->setText(QApplication::translate("mainPageClass", "R", nullptr));
        label_12->setText(QApplication::translate("mainPageClass", "B", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(meshTab), QApplication::translate("mainPageClass", "Mesh    ", nullptr));
        verifyTop->setText(QApplication::translate("mainPageClass", "Go", nullptr));
        inputValuePar->setText(QApplication::translate("mainPageClass", "Go", nullptr));
        swapLast->setText(QApplication::translate("mainPageClass", "Swap", nullptr));
        editWhorlOn->setText(QApplication::translate("mainPageClass", "Edit Whorl", nullptr));
        addWhorl->setText(QApplication::translate("mainPageClass", "Add Whorl", nullptr));
        editOn->setText(QApplication::translate("mainPageClass", "Edit Hierarchy", nullptr));
        deleteWhorlConf->setText(QApplication::translate("mainPageClass", "Delete", nullptr));
        verifyBot->setText(QApplication::translate("mainPageClass", "Go", nullptr));
        inputValueChi->setText(QApplication::translate("mainPageClass", "Go", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(editTab), QApplication::translate("mainPageClass", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainPageClass: public Ui_mainPageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPAGE_H
