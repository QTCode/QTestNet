#include "QtTestNet.h"
#include "ui_QtTestNet.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>
#include <nlohmann/json.hpp>
#include <fstream>
#include <QPushButton>
#include <iostream>



class QtTestNetPrivate : public Ui_QtTestNetClass
{
public:
	QNetworkAccessManager* m_serviceManager = nullptr;
};
QtTestNet::QtTestNet(QWidget* parent)
	: QWidget(parent), d_ptr(new QtTestNetPrivate)
{
	Q_D(QtTestNet);
	d->setupUi(this);
	d->m_serviceManager = new QNetworkAccessManager();
	QObject::connect(d->m_serviceManager, &QNetworkAccessManager::finished, this, &QtTestNet::queryFinish);
	QObject::connect(d->startDownloadBtn, &QPushButton::clicked, this, &QtTestNet::startRequest);
	//ui.setupUi(this);
}

QtTestNet::~QtTestNet()
{
}

void QtTestNet::startRequest()
{
	Q_D(QtTestNet);
	QNetworkRequest request;
	QSslConfiguration sslConfiguration(QSslConfiguration::defaultConfiguration());
	sslConfiguration.setProtocol(QSsl::TlsV1_2);
	request.setSslConfiguration(sslConfiguration);
	request.setUrl(QUrl("https://xy-api-fs.visual3d.cn/d/46d974b4-11d7-4166-9ba4-ce1fc2a5c340?md5=d100f0d7cf43834a459eac7a726af478&localfile=uploads/d1/00/f0/d100f0d7cf43834a459eac7a726af478"));
	//request.setRawHeader("Authorization",
	//	"Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJlbWFpbCI6ImxpdUBlbWFpbC5jb20iLCJleHAiOjE1NTg4NjU3NDMsImlkIjoiMTkyMWQ2NWUtYjJlOS00NzdiLWEyNDktMGZhZWQ4ZmM5ZmQzIiwibWV0YSI6IntcInR5cGVcIjpcIndlYlwifSIsInJvbGVzIjpbInVzZXIiXX0.QI-kVhYhW2IsVHy2YRswWPGwXR3qKdTqKbl4cu5A56w");
	request.setHeader(QNetworkRequest::ServerHeader, "application/json");
	d->m_serviceManager->get(request);

}
void QtTestNet::queryFinish(QNetworkReply* reply)
{
	Q_D(QtTestNet);
	QByteArray bytes = reply->readAll();
	QFile myfile("D:/myModel555555555555555555555555555555555.ply");
	if (!myfile.open(QFileDevice::ReadWrite))
	{
		std::cout << "error!" << std::endl;
	}
	else
	{
		myfile.write(bytes);
	}
	myfile.close();
	/*QString result(bytes);
	std::ofstream outfile;
	outfile.open("D:/mynet.txt");
	outfile << result.toStdString();
	std::cout << "finished!";
	nlohmann::json sJson = nlohmann::json::parse(result.toStdString());
	nlohmann::json scenJson = sJson["state"];*/
}
