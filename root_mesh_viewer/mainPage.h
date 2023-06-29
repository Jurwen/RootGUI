#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mainPage.h"
#include "glArea.h"
#include <QFileDialog>


class mainPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainPage(QWidget *parent = Q_NULLPTR);
	~mainPage();

public slots:
	void showSkelCheckBox(int _s);
	void showMeshCheckBox(int _s);
	void alphaChanged(int _s);
	void skelWidthChanged(int _s);
	void jetMinSpinChanged(double _s);
	void jetMaxSpinChanged(double _s);
	void meshColorRedChanged(int _s);
	void meshColorGreenChanged(int _s);
	void meshColorBlueChanged(int _s);
	void backColorRedChanged(int _s);
	void backColorGreenChanged(int _s);
	void backColorBlueChanged(int _s);
	void browseMeshClicked();
	void browseMeshClicked_obj();
	void browseSkelClicked();
	void browseAnnotationClicked();
	void showLvl0RootCheckBox(int _s);
	void showLvl1RootCheckBox(int _s);
	void showLvl2RootCheckBox(int _s);
	void showLvl3RootCheckBox(int _s);
	void showLvlLaterRootCheckBox(int _s);
	void whorlBelowCheckBox(int _s);
	void whorlAboveCheckBox(int _s);
	void nodalRootBelowCheckBox(int _s);
	void nodalRootAboveCheckBox(int _s);
	void showPlaneCheckBox(int _s);
	void skeletonColorComboBox(int _s);
	void nodalRootsbyWhorlsCheckBox(int _s);
	void editStateChange(int _s);
	//void addCurValue();
	void visualizeParent();
	void visualizeChild();
	void swapLastT();

	void editWhorlChange(int _s);
	void delWhorl();
	void addWhorl();
	void verifyTop();
	void verifyBot();
	void planeAdjustorChanged(int _s);

private:
    Ui::mainPageClass *ui;
	glArea *area;
};


