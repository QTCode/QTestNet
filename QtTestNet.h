#pragma once

#include <QWidget>


class QtTestNetPrivate;
class QNetworkReply;
class QtTestNet : public QWidget
{
	Q_OBJECT

public:
	QtTestNet(QWidget *parent = Q_NULLPTR);
	~QtTestNet();
	void startRequest();
public slots:
	void queryFinish(QNetworkReply* reply);
	
protected:
	QScopedPointer<QtTestNetPrivate> d_ptr;

private:
	Q_DECLARE_PRIVATE(QtTestNet);
	Q_DISABLE_COPY(QtTestNet);
};
