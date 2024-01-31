#pragma once
#include <qabstractitemmodel.h>
#include "Repository.h"

class IssueModel:public QAbstractTableModel
{
private:
	Repository& repo;

public:
	IssueModel(Repository& r) :repo{ r } {}
	int rowCount(const QModelIndex& parent = QModelIndex()) const;
	int columnCount(const QModelIndex& parent = QModelIndex()) const;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
	void add(Issue& i);
	void remove(int row);
};

