# include <QtTest>

class WorldCoordsToolsTests : public QObject
{
    Q_OBJECT
private slots:
    void worldToScreanX_test01();
    void worldToScreanX_test02();
    void worldToScreanX_test03();
    void worldToScreanX_test04();

    void worldToScreanY_test01();
    void worldToScreanY_test02();
    void worldToScreanY_test03();
    void worldToScreanY_test04();

    void worldToScreanZ_test01();
    void worldToScreanZ_test02();
    void worldToScreanZ_test03();
    void worldToScreanZ_test04();

    void worldToScrean_test01();
    void worldToScrean_test02();
    void worldToScrean_test03();
    void worldToScrean_test04();

    void worldNDCToScrean_test01();
    void worldNDCToScrean_test02();
    void worldNDCToScrean_test03();
    void worldNDCToScrean_test04();
};
