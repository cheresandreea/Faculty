#include "Model.h"
#include <vector>
#include <algorithm>
using namespace std;


int Model::rowCount(const QModelIndex& parent) const
{
	return repo.getIdeas().size();
}

int Model::columnCount(const QModelIndex& parent) const
{
	return 4;
}

QVariant Model::data(const QModelIndex& index, int role) const
{
	int row = index.row();
	int col = index.column();

	std::vector<Idea> ideas = repo.getIdeas();

	std::sort(ideas.begin(), ideas.end(), [&](Idea& a, Idea& b) 
		{
			return a.getAct() < b.getAct(); 
		});		
	Idea idea = ideas[row];

	if (role == Qt::DisplayRole)
	{
		switch (col)
		{
		case 0:
			return QString::fromStdString(idea.getDescription());
		case 1:
			return QString::fromStdString(idea.getStatus());
		case 2:
			return QString::fromStdString(std::to_string(idea.getAct()));
		case 3:
			return QString::fromStdString(idea.getCreator());
		default:
			break;
		}
	}
	return QVariant();
}

QVariant Model::headerData(int section, Qt::Orientation orientation, int role) const
{
	if(role == Qt::DisplayRole)
		if (orientation == Qt::Horizontal)
		{
			switch (section)
			{
			case 0:
				return QString("Description");
			case 1:
				return QString("Status");
			case 2:
				return QString("Act");
			case 3:
				return QString("Creator");
			default:
				break;
			}
		}

	return QVariant();
}

void Model::add(Idea& i)
{
	int n = repo.getIdeas().size();
	this->beginInsertRows(QModelIndex(), n, n);
	repo.add(i);
	this->endInsertRows();
}
