#include "IssueModel.h"
#include <vector>

int IssueModel::rowCount(const QModelIndex& parent) const
{
    return repo.sizeIssues();
}

int IssueModel::columnCount(const QModelIndex& parent) const
{
    return 4;
}

QVariant IssueModel::data(const QModelIndex& index, int role) const
{
    int col = index.column();
    int row = index.row();
    std::vector<Issue> issues = repo.getIssues();

    std::sort(issues.begin(), issues.end(), [&](Issue& i1, Issue& i2)
        {
            if (i1.getStatus() == i2.getStatus())
                return i1.getDescription() < i2.getDescription();
            else return i1.getStatus() > i2.getStatus();
        });


    Issue issue = issues[row];

    if (role == Qt::DisplayRole)
    {
        switch (col)
        {
        case 0:
            return QString::fromStdString(issue.getDescription());
        case 1:
            return QString::fromStdString(issue.getStatus());
        case 2:
            return QString::fromStdString(issue.getReporter());
        case 3:
            return QString::fromStdString(issue.getSolver());
        default:
            break;
        }
    }



    return QVariant();
}

QVariant IssueModel::headerData(int section, Qt::Orientation orientation, int role) const
{

    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal)
        {
            switch (section)
            {
            case 0:
                return QString::fromStdString("Description");
            case 1:
                return QString::fromStdString("Status");
            case 2:
                return QString::fromStdString("Reporter");
            case 3:
                return QString::fromStdString("Solver");
            default:
                break;
            }
        }


    }

    return QVariant();
}


void IssueModel::add(Issue& i)
{
    int n = repo.getIssues().size();

    this->beginInsertRows(QModelIndex{}, n, n);

    repo.addIssue(i);

    this->endInsertRows();
}

void IssueModel::remove(int pos)
{
    this->beginRemoveRows(QModelIndex{}, pos, pos);

    repo.removeIssue(pos);

    this->endRemoveRows();
    
}