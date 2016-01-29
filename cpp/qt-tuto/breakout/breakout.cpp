#include <QPainter>
#include <QApplication>
#include "breakout.h"

Breakout::Breakout(QWidget *parent) : QWidget(parent) {
	setStyleSheet("background-color : #000;");

	x = 0;
	gameOver = false;
	gameWon = false;
	paused = false;
	gameStarted = false;
	ball = new Ball();
	paddle = new Paddle();

	int k = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 6; j++) {
			bricks[k] = new Brick(j * 40 + 30, i * 10 + 50);
			k++;
		}
	}
}

Breakout::~Breakout() {
	delete ball;
	delete paddle;

	for (int i = 0; i < N_OF_BRICKS; i++) {
		delete bricks[i];
	}
}

void Breakout::paintEvent(QPaintEvent *e) {
	Q_UNUSED(e);

	QPainter painter(this);

	if (gameOver)
		finishGame(&painter, "Game lost");
	else if (gameWon)
		finishGame(&painter, "Victory");
	else
		drawObjects(&painter);
}

void Breakout::drawObjects(QPainter *painter) {
	painter->drawImage(ball->getRect(), ball->getImage());
	painter->drawImage(paddle->getRect(), paddle->getImage());

	for (int i = 0; i < N_OF_BRICKS; i++) {
		if (!bricks[i]->isDestroyed())
			painter->drawImage(bricks[i]->getRect(), bricks[i]->getImage());
	}
}

void Breakout::finishGame(QPainter *painter, QString message) {
	QFont font("Courier", 15, QFont::DemiBold);
	QFontMetrics fm(font);
	int textWidth = fm.width(message);

	painter->setFont(font);
	int h = height();
	int w = width();

	painter->translate(QPoint(w / 2, h / 2));
	painter->drawText(-textWidth / 2, 0, message);
}

void Breakout::timerEvent(QTimerEvent *e) {
	Q_UNUSED(e)
	
	moveObjects();
	//checkCollision();
	repaint();
}

void Breakout::moveObjects() {
	//ball->autoMove();
	paddle->move();
}

void Breakout::keyReleaseEvent(QKeyEvent *e) {
	int dx = 0;

	switch (e->key()) {
		case Qt::Key_Left:
			dx = 0;
			paddle->setDx(dx);
			break;

		case Qt::Key_Right:
			dx = 0;
			paddle->setDx(dx);
			break;
	}
}

void Breakout::keyPressEvent(QKeyEvent *e) {
	int dx = 0;

	switch (e->key()) {
		case Qt::Key_Left:
			dx = -1;
			paddle->setDx(dx);
			break;

		case Qt::Key_Right:
			dx = 1;
			paddle->setDx(dx);
			break;

		case Qt::Key_Space:
			startGame();
			break;

		default:
			QWidget::keyPressEvent(e);
	}
}

void Breakout::startGame() {
	if (!gameStarted) {
		//ball->resetState();
		paddle->resetState();

		for (int i = 0; i < N_OF_BRICKS; i++)
			bricks[i]->setDestroyed(false);

		gameOver = false;
		gameWon = false;
		gameStarted = true;
		timerId = startTimer(DELAY);
	}
}

void Breakout::pauseGame() {}
void Breakout::stopGame() {}
void Breakout::victory() {}
void Breakout::checkCollision() {}
