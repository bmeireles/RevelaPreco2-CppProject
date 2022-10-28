#ifndef COMPANYLIST_H
#define COMPANYLIST_H

#include <QString>
#include <QList>
#include <QJsonObject>
#include <QStandardItemModel>

struct Company {
    QString id;
    QString name;
    QString address;
    QString pictureFilePath;
    QString regNumber; //company's registration number
    //QString locationPath; // path to find the company on google maps, this info shows
    //up on the detailed page of the company

    QJsonObject toJson() const;
    void fromJson(const QJsonObject& obj);
};

//A list of Companies
class CompanyList
{
public:
    CompanyList();

    void loadCompanyFile(const QString& filePath); //load list of companies from a json file
    //void loadCompanyDB(const QString& filePath); //load list of companies from a database
    //void saveCompanyFile(); //save new info about a company on a json file

    void addCompany(const Company& company);
    void removeCompany(const QString& id);
    void updateCompany(const Company& company);
    int findCompany(const QString& id);
    QList<Company>& getCompanies();

private:
    QList<Company> companies;

};

class CompanyModel: public QStandardItemModel {
public:
    CompanyModel(QObject* parent = nullptr);

    // Copy the data from CompanyList to the model
    void setList(CompanyList* list);
};

#endif // COMPANYLIST_H
