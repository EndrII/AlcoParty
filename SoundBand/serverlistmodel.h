#ifndef SERVERLISTMODEL_H
#define SERVERLISTMODEL_H

#include <QAbstractListModel>

class SyncEngine;
class ETcpSocket;

/**
 * @brief The ServerListModel class
 */
class ServerListModel : public QAbstractListModel
{
    Q_OBJECT

private:
    const SyncEngine * syncEngine;
    const QList<ETcpSocket*> *servers;
    int itemCount;

private slots:
    /**
     * @brief onServersListsChanged check new Servers
     */
    void onServersListsChanged();
protected:
    bool canFetchMore(const QModelIndex &parent) const override;
    void fetchMore(const QModelIndex &parent) override;

public:
    explicit ServerListModel(QObject *parent = nullptr);

    /**
     * @brief The ServerListRoles enum
     * nameRole - name of playlist
     * imageRole - image of playlist
     */
    enum ServerListRoles {
        nameRole = Qt::UserRole + 1
    };

    /**
     * @brief setSource
     * @param engine
     */
    void setSource(const SyncEngine* engine);

    /**
     * @brief AnimalModel::roleNames
     * @return pair of roles and value
     */
    QHash<int, QByteArray> roleNames() const;

    /**
     * @brief rowCount
     * @param parent
     * @return count of playlists
     */
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    /**
     * @brief data standart dataselector
     * @param index
     * @param role
     * @return
     */
    QVariant data(const QModelIndex &index, int role = nameRole) const override;


signals:

public slots:
};

#endif // SERVERLISTMODEL_H
