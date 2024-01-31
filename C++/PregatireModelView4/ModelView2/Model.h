#pragma once
#include "Service.h"
#include <qabstractitemmodel.h>

class Model: public QAbstractTableModel
{
private:
	Repository& repo;
public:
	Model(Repository& repo) : repo(repo) {}
	int rowCount(const QModelIndex& parent = QModelIndex()) const;
	int columnCount(const QModelIndex& parent = QModelIndex()) const;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
	void add(Idea& i);
	~Model() {}

};

