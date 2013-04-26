#ifndef GAMESPACE_H
#define GAMESPACE_H

// Standard
#include <vector>

// Qt
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>

// Local
#include "thing.h"

class MainWindow;

class GameSpace : public QGraphicsView
{
	Q_OBJECT
	
	public:
		explicit GameSpace(MainWindow* parent);
		void startNewGame();
		// Accessors
		/** Get a pointer to the scene */
		QGraphicsScene* scene() { return scene_; }
		/** Get whether a game is currently in progress */
		bool gameInProgress() { return gameInProgress_; }
	private:
		QGraphicsScene* scene_;
		QPixmap* steve_;
		std::vector<Thing*> enemies_;
		QPixmap* zombie_;
		QPixmap* spider_;
		QPixmap* creeper_;
		QPixmap* skeleton_;
		QPixmap* enderman_;
		std::vector<Thing*> items_;
		QPixmap* heart_;
		bool gameInProgress_;
};

#endif // GAMESPACE_H
