#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
	// needed in order to call qApp->close()
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>

#include "gamespace.h"

#define WINDOW_MAX_X 800
#define WINDOW_MAX_Y WINDOW_MAX_X*3/4

class MainWindow : public QWidget
{
	Q_OBJECT
	
	public: // Member functions
		explicit MainWindow();

	public slots:
		void startNewGame();
		void quitGame();
		void pauseGame();
	
	private: // UI elements
		QHBoxLayout* mainLayoutUI;
			QVBoxLayout* leftLayoutUI;
				QPushButton* startButtonUI;
				QPushButton* quitButtonUI;
				QPushButton* pauseButtonUI;
				QLabel* userNameUI;
				QLabel* scoreUI;
			QLabel* statusLabelUI;
			QVBoxLayout* gameSpaceLayoutUI;
				GameSpace* gameSpaceUI;
};

#endif // MAINWINDOW_H
