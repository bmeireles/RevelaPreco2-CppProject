#include "companylist.h"

#include <QDebug>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

CompanyList::CompanyList()
{

}

void CompanyList::loadCompanyFile(const QString &filePath)
{
    if (!QFile::exists(filePath)) {
        qDebug() << "File " << filePath << " doesn't exist";
        return;
    }

    QFile file(filePath);
    if (!file.open(QFile::ReadOnly)) {
        qDebug() << "Can't open file " << filePath;
        return;
    }
    QByteArray data = file.readAll();

    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data, &parseError);
    if (parseError.error != QJsonParseError::NoError) {
        qDebug() << "Json parse error " << parseError.errorString();
        return;
    }

    if (!jsonDoc.isArray()) {
        qDebug() << "The json file is not an array";
        return;
    }
    auto array = jsonDoc.array();
    for (const QJsonValue& value : array) {
        QJsonObject obj = value.toObject();
        Company company;
        company.fromJson(obj);
        addCompany(company);
        qDebug() << company.toJson();
    }

}

void CompanyList::addCompany(const Company &company)
{
    if (findCompany(company.id) != -1)
        return;

    companies.append(company);
}

void CompanyList::removeCompany(const QString &id)
{
    int index = findCompany(id);
}

void CompanyList::updateCompany(const Company &company)
{
    int index = findCompany(company.id);
    if (index == -1)
        return;

    companies[index] = company;
}

int CompanyList::findCompany(const QString &id)
{
    int index = 0;
    for (const auto& company: companies) {
        if (company.id == id)
            return index;
        index ++;
    }
    return -1;
}

QList<Company> &CompanyList::getCompanies()
{
    return companies;
}

QJsonObject Company::toJson() const
{
    QJsonObject obj;
    obj["id"] = id;
    obj["name"] = name;
    obj["address"] = address;
    obj["pictureFilePath"] = pictureFilePath;
    obj["regNumber"] = regNumber;
    return obj;
}

void Company::fromJson(const QJsonObject &obj)
{
    // TODO: Check if all the fields exist

    id = obj["id"].toString();
    name = obj["name"].toString();
    address = obj["address"].toString();
    pictureFilePath = obj["pictureFilePath"].toString();
    regNumber = obj["regNumber"].toString();
}

CompanyModel::CompanyModel(QObject *parent): QStandardItemModel(parent)
{

}

void CompanyModel::setList(CompanyList *list)
{
    auto data = list->getCompanies();
    setColumnCount(5);
    setHeaderData(0, Qt::Horizontal, "ID");
    setHeaderData(1, Qt::Horizontal, "Name");
    setHeaderData(2, Qt::Horizontal, "Address");
    setHeaderData(3, Qt::Horizontal, "Picture");
    setHeaderData(4, Qt::Horizontal, "Registration Number");
    setRowCount(data.count());

    int row = 0;
//    for (auto itr = data.begin(); itr != data.end(); itr ++) {
//        setData(index(row, 0), itr->id);
//        setData(index(row, 0), itr->name, ListViewDelegate::DataRole::TitleRole);
//        setData(index(row, 0), itr->address, ListViewDelegate::DataRole::TextRole);
//        QIcon icon(itr->pictureFilePath);
//        setData(index(row, 0), itr->regNumber, ListViewDelegate::DataRole::TitleRole);
//        setData(index(row, 0), icon, Qt::DecorationRole);
//        row ++;
//    }
}

