/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_Logo;
    QSpacerItem *horizontalSpacer_12;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidget_InstrumentList;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Search;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *checkBox_mDNS;
    QSpacerItem *horizontalSpacer_18;
    QSpacerItem *verticalSpacer_7;
    QTabWidget *tabWidget;
    QWidget *tab_SCPI;
    QVBoxLayout *verticalLayout_12;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_7;
    QComboBox *comboBox_SCPI_Command;
    QPushButton *pushButton_SCPI_Clear;
    QPushButton *pushButton_SCPI_Send;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_3;
    QTextBrowser *textBrowser_SCPI_Response;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_SCPI_CLS;
    QPushButton *pushButton_SCPI_ESE;
    QPushButton *pushButton_SCPI_ESEQuestion;
    QPushButton *pushButton_SCPI_ESRQuestion;
    QPushButton *pushButton_SCPI_IDNQuestion;
    QPushButton *pushButton_SCPI_OPC;
    QPushButton *pushButton_SCPI_OPCQuestion;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_SCPI_RST;
    QPushButton *pushButton_SCPI_SRE;
    QPushButton *pushButton_SCPI_SREQuestion;
    QPushButton *pushButton_SCPI_STBQuestion;
    QPushButton *pushButton_SCPI_TSTQuestion;
    QPushButton *pushButton_SCPI_WAI;
    QPushButton *pushButton_SCPI_Blank;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_22;
    QHBoxLayout *horizontalLayout_14;
    QPushButton *pushButton_SCPI_SystemVersionQuery;
    QPushButton *pushButton_SCPI_SystemErrorQuery;
    QPushButton *pushButton_SCPI_SystemErrorNextQuery;
    QPushButton *pushButton_SCPIP_StatusOperationQuery;
    QPushButton *pushButton_SCPI_StatusPreset;
    QWidget *tab_Screenshot;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_8;
    QGraphicsView *graphicsView_Screenshot;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_Screenshot_LiveView;
    QPushButton *pushButton_Screenshot_TakeScreenshot;
    QPushButton *pushButton_Screenshot_Save;
    QSpacerItem *horizontalSpacer_5;
    QWidget *tab_Benchmark;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_8;
    QProgressBar *progressBar;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QSpinBox *spinBox_BenchmarkRequests;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_Benchmark_Start;
    QSpacerItem *horizontalSpacer_7;
    QWidget *tab_DataRecorder;
    QVBoxLayout *verticalLayout_11;
    QtCharts::QChartView *chartView;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_18;
    QLineEdit *lineEdit;
    QLabel *label_19;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer_17;
    QSpinBox *spinBox_DataRecorderRate;
    QLabel *label_20;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_15;
    QPushButton *pushButton_DataRecorder_Start;
    QPushButton *pushButton_DataRecorder_Save;
    QSpacerItem *horizontalSpacer_16;
    QWidget *tab_Settings;
    QGridLayout *gridLayout_6;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *horizontalSpacer_14;
    QGridLayout *gridLayout_5;
    QLabel *label_17;
    QSpinBox *spinBox_SearchTimeout;
    QLabel *label_16;
    QLabel *label_7;
    QSpinBox *spinBox_SCPITimeout;
    QLabel *label_14;
    QLabel *label_13;
    QSpinBox *spinBox_ScreenshotTimeout;
    QLabel *label_15;
    QLabel *label_21;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *verticalSpacer_9;
    QWidget *tab_About;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_10;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_10;
    QVBoxLayout *verticalLayout;
    QLabel *label_8;
    QLabel *label_11;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_9;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_10;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *verticalSpacer_4;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(880, 800);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(700, 600));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setSizeConstraint(QLayout::SetNoConstraint);
        label_Logo = new QLabel(centralWidget);
        label_Logo->setObjectName(QString::fromUtf8("label_Logo"));
        label_Logo->setPixmap(QPixmap(QString::fromUtf8(":/images/lxi-tools_256x256.png")));
        label_Logo->setScaledContents(true);

        horizontalLayout_6->addWidget(label_Logo);

        horizontalSpacer_12 = new QSpacerItem(4, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_12);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tableWidget_InstrumentList = new QTableWidget(centralWidget);
        if (tableWidget_InstrumentList->columnCount() < 2)
            tableWidget_InstrumentList->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        tableWidget_InstrumentList->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignCenter);
        tableWidget_InstrumentList->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget_InstrumentList->setObjectName(QString::fromUtf8("tableWidget_InstrumentList"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableWidget_InstrumentList->sizePolicy().hasHeightForWidth());
        tableWidget_InstrumentList->setSizePolicy(sizePolicy1);
        tableWidget_InstrumentList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_InstrumentList->setProperty("showDropIndicator", QVariant(false));
        tableWidget_InstrumentList->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget_InstrumentList->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_InstrumentList->setShowGrid(false);
        tableWidget_InstrumentList->horizontalHeader()->setVisible(true);
        tableWidget_InstrumentList->horizontalHeader()->setDefaultSectionSize(542);
        tableWidget_InstrumentList->horizontalHeader()->setHighlightSections(false);
        tableWidget_InstrumentList->horizontalHeader()->setMinimumSectionSize(57);
        tableWidget_InstrumentList->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget_InstrumentList->horizontalHeader()->setStretchLastSection(true);
        tableWidget_InstrumentList->verticalHeader()->setVisible(false);

        verticalLayout_2->addWidget(tableWidget_InstrumentList);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(350, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        pushButton_Search = new QPushButton(centralWidget);
        pushButton_Search->setObjectName(QString::fromUtf8("pushButton_Search"));

        horizontalLayout_5->addWidget(pushButton_Search);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        checkBox_mDNS = new QCheckBox(centralWidget);
        checkBox_mDNS->setObjectName(QString::fromUtf8("checkBox_mDNS"));
        checkBox_mDNS->setEnabled(false);
        checkBox_mDNS->setChecked(false);

        horizontalLayout_5->addWidget(checkBox_mDNS);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_18);


        verticalLayout_2->addLayout(horizontalLayout_5);


        horizontalLayout_6->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_6);

        verticalSpacer_7 = new QSpacerItem(20, 4, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_7);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy2);
        tab_SCPI = new QWidget();
        tab_SCPI->setObjectName(QString::fromUtf8("tab_SCPI"));
        verticalLayout_12 = new QVBoxLayout(tab_SCPI);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_2 = new QLabel(tab_SCPI);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_4->addWidget(label_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        comboBox_SCPI_Command = new QComboBox(tab_SCPI);
        comboBox_SCPI_Command->setObjectName(QString::fromUtf8("comboBox_SCPI_Command"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(comboBox_SCPI_Command->sizePolicy().hasHeightForWidth());
        comboBox_SCPI_Command->setSizePolicy(sizePolicy3);
        comboBox_SCPI_Command->setMinimumSize(QSize(0, 0));
        comboBox_SCPI_Command->setAcceptDrops(true);
        comboBox_SCPI_Command->setEditable(true);

        horizontalLayout_7->addWidget(comboBox_SCPI_Command);

        pushButton_SCPI_Clear = new QPushButton(tab_SCPI);
        pushButton_SCPI_Clear->setObjectName(QString::fromUtf8("pushButton_SCPI_Clear"));

        horizontalLayout_7->addWidget(pushButton_SCPI_Clear);

        pushButton_SCPI_Send = new QPushButton(tab_SCPI);
        pushButton_SCPI_Send->setObjectName(QString::fromUtf8("pushButton_SCPI_Send"));

        horizontalLayout_7->addWidget(pushButton_SCPI_Send);


        verticalLayout_4->addLayout(horizontalLayout_7);


        verticalLayout_12->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_3 = new QLabel(tab_SCPI);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_5->addWidget(label_3);

        textBrowser_SCPI_Response = new QTextBrowser(tab_SCPI);
        textBrowser_SCPI_Response->setObjectName(QString::fromUtf8("textBrowser_SCPI_Response"));
        textBrowser_SCPI_Response->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        textBrowser_SCPI_Response->setTextInteractionFlags(Qt::TextBrowserInteraction);

        verticalLayout_5->addWidget(textBrowser_SCPI_Response);


        verticalLayout_12->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_12 = new QLabel(tab_SCPI);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_6->addWidget(label_12);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_SCPI_CLS = new QPushButton(tab_SCPI);
        pushButton_SCPI_CLS->setObjectName(QString::fromUtf8("pushButton_SCPI_CLS"));

        horizontalLayout_3->addWidget(pushButton_SCPI_CLS);

        pushButton_SCPI_ESE = new QPushButton(tab_SCPI);
        pushButton_SCPI_ESE->setObjectName(QString::fromUtf8("pushButton_SCPI_ESE"));

        horizontalLayout_3->addWidget(pushButton_SCPI_ESE);

        pushButton_SCPI_ESEQuestion = new QPushButton(tab_SCPI);
        pushButton_SCPI_ESEQuestion->setObjectName(QString::fromUtf8("pushButton_SCPI_ESEQuestion"));

        horizontalLayout_3->addWidget(pushButton_SCPI_ESEQuestion);

        pushButton_SCPI_ESRQuestion = new QPushButton(tab_SCPI);
        pushButton_SCPI_ESRQuestion->setObjectName(QString::fromUtf8("pushButton_SCPI_ESRQuestion"));

        horizontalLayout_3->addWidget(pushButton_SCPI_ESRQuestion);

        pushButton_SCPI_IDNQuestion = new QPushButton(tab_SCPI);
        pushButton_SCPI_IDNQuestion->setObjectName(QString::fromUtf8("pushButton_SCPI_IDNQuestion"));

        horizontalLayout_3->addWidget(pushButton_SCPI_IDNQuestion);

        pushButton_SCPI_OPC = new QPushButton(tab_SCPI);
        pushButton_SCPI_OPC->setObjectName(QString::fromUtf8("pushButton_SCPI_OPC"));

        horizontalLayout_3->addWidget(pushButton_SCPI_OPC);

        pushButton_SCPI_OPCQuestion = new QPushButton(tab_SCPI);
        pushButton_SCPI_OPCQuestion->setObjectName(QString::fromUtf8("pushButton_SCPI_OPCQuestion"));

        horizontalLayout_3->addWidget(pushButton_SCPI_OPCQuestion);


        verticalLayout_6->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton_SCPI_RST = new QPushButton(tab_SCPI);
        pushButton_SCPI_RST->setObjectName(QString::fromUtf8("pushButton_SCPI_RST"));

        horizontalLayout_4->addWidget(pushButton_SCPI_RST);

        pushButton_SCPI_SRE = new QPushButton(tab_SCPI);
        pushButton_SCPI_SRE->setObjectName(QString::fromUtf8("pushButton_SCPI_SRE"));

        horizontalLayout_4->addWidget(pushButton_SCPI_SRE);

        pushButton_SCPI_SREQuestion = new QPushButton(tab_SCPI);
        pushButton_SCPI_SREQuestion->setObjectName(QString::fromUtf8("pushButton_SCPI_SREQuestion"));

        horizontalLayout_4->addWidget(pushButton_SCPI_SREQuestion);

        pushButton_SCPI_STBQuestion = new QPushButton(tab_SCPI);
        pushButton_SCPI_STBQuestion->setObjectName(QString::fromUtf8("pushButton_SCPI_STBQuestion"));

        horizontalLayout_4->addWidget(pushButton_SCPI_STBQuestion);

        pushButton_SCPI_TSTQuestion = new QPushButton(tab_SCPI);
        pushButton_SCPI_TSTQuestion->setObjectName(QString::fromUtf8("pushButton_SCPI_TSTQuestion"));

        horizontalLayout_4->addWidget(pushButton_SCPI_TSTQuestion);

        pushButton_SCPI_WAI = new QPushButton(tab_SCPI);
        pushButton_SCPI_WAI->setObjectName(QString::fromUtf8("pushButton_SCPI_WAI"));

        horizontalLayout_4->addWidget(pushButton_SCPI_WAI);

        pushButton_SCPI_Blank = new QPushButton(tab_SCPI);
        pushButton_SCPI_Blank->setObjectName(QString::fromUtf8("pushButton_SCPI_Blank"));
        pushButton_SCPI_Blank->setEnabled(false);

        horizontalLayout_4->addWidget(pushButton_SCPI_Blank);


        verticalLayout_6->addLayout(horizontalLayout_4);


        verticalLayout_12->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_22 = new QLabel(tab_SCPI);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        verticalLayout_7->addWidget(label_22);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        pushButton_SCPI_SystemVersionQuery = new QPushButton(tab_SCPI);
        pushButton_SCPI_SystemVersionQuery->setObjectName(QString::fromUtf8("pushButton_SCPI_SystemVersionQuery"));

        horizontalLayout_14->addWidget(pushButton_SCPI_SystemVersionQuery);

        pushButton_SCPI_SystemErrorQuery = new QPushButton(tab_SCPI);
        pushButton_SCPI_SystemErrorQuery->setObjectName(QString::fromUtf8("pushButton_SCPI_SystemErrorQuery"));

        horizontalLayout_14->addWidget(pushButton_SCPI_SystemErrorQuery);

        pushButton_SCPI_SystemErrorNextQuery = new QPushButton(tab_SCPI);
        pushButton_SCPI_SystemErrorNextQuery->setObjectName(QString::fromUtf8("pushButton_SCPI_SystemErrorNextQuery"));

        horizontalLayout_14->addWidget(pushButton_SCPI_SystemErrorNextQuery);

        pushButton_SCPIP_StatusOperationQuery = new QPushButton(tab_SCPI);
        pushButton_SCPIP_StatusOperationQuery->setObjectName(QString::fromUtf8("pushButton_SCPIP_StatusOperationQuery"));

        horizontalLayout_14->addWidget(pushButton_SCPIP_StatusOperationQuery);

        pushButton_SCPI_StatusPreset = new QPushButton(tab_SCPI);
        pushButton_SCPI_StatusPreset->setObjectName(QString::fromUtf8("pushButton_SCPI_StatusPreset"));

        horizontalLayout_14->addWidget(pushButton_SCPI_StatusPreset);


        verticalLayout_7->addLayout(horizontalLayout_14);


        verticalLayout_12->addLayout(verticalLayout_7);

        tabWidget->addTab(tab_SCPI, QString());
        tab_Screenshot = new QWidget();
        tab_Screenshot->setObjectName(QString::fromUtf8("tab_Screenshot"));
        gridLayout_2 = new QGridLayout(tab_Screenshot);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        graphicsView_Screenshot = new QGraphicsView(tab_Screenshot);
        graphicsView_Screenshot->setObjectName(QString::fromUtf8("graphicsView_Screenshot"));
        graphicsView_Screenshot->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView_Screenshot->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView_Screenshot->setDragMode(QGraphicsView::ScrollHandDrag);

        verticalLayout_8->addWidget(graphicsView_Screenshot);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        pushButton_Screenshot_LiveView = new QPushButton(tab_Screenshot);
        pushButton_Screenshot_LiveView->setObjectName(QString::fromUtf8("pushButton_Screenshot_LiveView"));

        horizontalLayout_2->addWidget(pushButton_Screenshot_LiveView);

        pushButton_Screenshot_TakeScreenshot = new QPushButton(tab_Screenshot);
        pushButton_Screenshot_TakeScreenshot->setObjectName(QString::fromUtf8("pushButton_Screenshot_TakeScreenshot"));

        horizontalLayout_2->addWidget(pushButton_Screenshot_TakeScreenshot);

        pushButton_Screenshot_Save = new QPushButton(tab_Screenshot);
        pushButton_Screenshot_Save->setObjectName(QString::fromUtf8("pushButton_Screenshot_Save"));
        pushButton_Screenshot_Save->setEnabled(false);

        horizontalLayout_2->addWidget(pushButton_Screenshot_Save);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout_8->addLayout(horizontalLayout_2);


        gridLayout_2->addLayout(verticalLayout_8, 0, 0, 1, 1);

        tabWidget->addTab(tab_Screenshot, QString());
        tab_Benchmark = new QWidget();
        tab_Benchmark->setObjectName(QString::fromUtf8("tab_Benchmark"));
        gridLayout_3 = new QGridLayout(tab_Benchmark);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        label_6 = new QLabel(tab_Benchmark);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QFont font;
        font.setFamily(QString::fromUtf8("Abyssinica SIL"));
        font.setPointSize(18);
        font.setBold(false);
        font.setWeight(50);
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(label_6);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_8);

        progressBar = new QProgressBar(tab_Benchmark);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy4);
        progressBar->setMaximum(1000);
        progressBar->setValue(0);
        progressBar->setInvertedAppearance(false);

        horizontalLayout_9->addWidget(progressBar);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_9);


        verticalLayout_9->addLayout(horizontalLayout_9);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_4 = new QLabel(tab_Benchmark);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font1;
        font1.setKerning(true);
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_4);

        spinBox_BenchmarkRequests = new QSpinBox(tab_Benchmark);
        spinBox_BenchmarkRequests->setObjectName(QString::fromUtf8("spinBox_BenchmarkRequests"));
        sizePolicy.setHeightForWidth(spinBox_BenchmarkRequests->sizePolicy().hasHeightForWidth());
        spinBox_BenchmarkRequests->setSizePolicy(sizePolicy);
        spinBox_BenchmarkRequests->setAlignment(Qt::AlignCenter);
        spinBox_BenchmarkRequests->setMinimum(1);
        spinBox_BenchmarkRequests->setMaximum(9999);
        spinBox_BenchmarkRequests->setValue(1000);

        horizontalLayout->addWidget(spinBox_BenchmarkRequests);

        label_5 = new QLabel(tab_Benchmark);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);


        verticalLayout_9->addLayout(horizontalLayout);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_6);

        pushButton_Benchmark_Start = new QPushButton(tab_Benchmark);
        pushButton_Benchmark_Start->setObjectName(QString::fromUtf8("pushButton_Benchmark_Start"));

        horizontalLayout_8->addWidget(pushButton_Benchmark_Start);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_7);


        verticalLayout_9->addLayout(horizontalLayout_8);


        gridLayout_3->addLayout(verticalLayout_9, 0, 0, 1, 1);

        tabWidget->addTab(tab_Benchmark, QString());
        tab_DataRecorder = new QWidget();
        tab_DataRecorder->setObjectName(QString::fromUtf8("tab_DataRecorder"));
        verticalLayout_11 = new QVBoxLayout(tab_DataRecorder);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        chartView = new QtCharts::QChartView(tab_DataRecorder);
        chartView->setObjectName(QString::fromUtf8("chartView"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(chartView->sizePolicy().hasHeightForWidth());
        chartView->setSizePolicy(sizePolicy5);

        verticalLayout_11->addWidget(chartView);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_18 = new QLabel(tab_DataRecorder);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_12->addWidget(label_18);

        lineEdit = new QLineEdit(tab_DataRecorder);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_12->addWidget(lineEdit);

        label_19 = new QLabel(tab_DataRecorder);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout_12->addWidget(label_19);

        lineEdit_2 = new QLineEdit(tab_DataRecorder);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(true);

        horizontalLayout_12->addWidget(lineEdit_2);


        verticalLayout_11->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_17);

        spinBox_DataRecorderRate = new QSpinBox(tab_DataRecorder);
        spinBox_DataRecorderRate->setObjectName(QString::fromUtf8("spinBox_DataRecorderRate"));
        spinBox_DataRecorderRate->setMinimum(1);
        spinBox_DataRecorderRate->setMaximum(100);
        spinBox_DataRecorderRate->setValue(10);

        horizontalLayout_13->addWidget(spinBox_DataRecorderRate);

        label_20 = new QLabel(tab_DataRecorder);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_13->addWidget(label_20);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_2);


        verticalLayout_11->addLayout(horizontalLayout_13);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_15);

        pushButton_DataRecorder_Start = new QPushButton(tab_DataRecorder);
        pushButton_DataRecorder_Start->setObjectName(QString::fromUtf8("pushButton_DataRecorder_Start"));

        horizontalLayout_11->addWidget(pushButton_DataRecorder_Start);

        pushButton_DataRecorder_Save = new QPushButton(tab_DataRecorder);
        pushButton_DataRecorder_Save->setObjectName(QString::fromUtf8("pushButton_DataRecorder_Save"));

        horizontalLayout_11->addWidget(pushButton_DataRecorder_Save);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_16);


        verticalLayout_11->addLayout(horizontalLayout_11);

        tabWidget->addTab(tab_DataRecorder, QString());
        tab_Settings = new QWidget();
        tab_Settings->setObjectName(QString::fromUtf8("tab_Settings"));
        gridLayout_6 = new QGridLayout(tab_Settings);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        verticalSpacer_8 = new QSpacerItem(20, 164, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_8, 0, 1, 1, 1);

        horizontalSpacer_14 = new QSpacerItem(273, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_14, 1, 0, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_17 = new QLabel(tab_Settings);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_5->addWidget(label_17, 0, 0, 1, 1);

        spinBox_SearchTimeout = new QSpinBox(tab_Settings);
        spinBox_SearchTimeout->setObjectName(QString::fromUtf8("spinBox_SearchTimeout"));
        spinBox_SearchTimeout->setAlignment(Qt::AlignCenter);
        spinBox_SearchTimeout->setMaximum(999);
        spinBox_SearchTimeout->setValue(1);

        gridLayout_5->addWidget(spinBox_SearchTimeout, 0, 1, 1, 1);

        label_16 = new QLabel(tab_Settings);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_5->addWidget(label_16, 0, 2, 1, 1);

        label_7 = new QLabel(tab_Settings);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_5->addWidget(label_7, 1, 0, 1, 1);

        spinBox_SCPITimeout = new QSpinBox(tab_Settings);
        spinBox_SCPITimeout->setObjectName(QString::fromUtf8("spinBox_SCPITimeout"));
        spinBox_SCPITimeout->setAlignment(Qt::AlignCenter);
        spinBox_SCPITimeout->setMaximum(999);
        spinBox_SCPITimeout->setValue(3);

        gridLayout_5->addWidget(spinBox_SCPITimeout, 1, 1, 1, 1);

        label_14 = new QLabel(tab_Settings);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_5->addWidget(label_14, 1, 2, 1, 1);

        label_13 = new QLabel(tab_Settings);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_5->addWidget(label_13, 2, 0, 1, 1);

        spinBox_ScreenshotTimeout = new QSpinBox(tab_Settings);
        spinBox_ScreenshotTimeout->setObjectName(QString::fromUtf8("spinBox_ScreenshotTimeout"));
        spinBox_ScreenshotTimeout->setAlignment(Qt::AlignCenter);
        spinBox_ScreenshotTimeout->setMaximum(999);
        spinBox_ScreenshotTimeout->setValue(15);

        gridLayout_5->addWidget(spinBox_ScreenshotTimeout, 2, 1, 1, 1);

        label_15 = new QLabel(tab_Settings);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_5->addWidget(label_15, 2, 2, 1, 1);

        label_21 = new QLabel(tab_Settings);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_5->addWidget(label_21, 3, 0, 1, 1);

        comboBox = new QComboBox(tab_Settings);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout_5->addWidget(comboBox, 3, 1, 1, 2);


        gridLayout_6->addLayout(gridLayout_5, 1, 1, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(272, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_13, 1, 2, 1, 1);

        verticalSpacer_9 = new QSpacerItem(20, 163, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_9, 2, 1, 1, 1);

        tabWidget->addTab(tab_Settings, QString());
        tab_About = new QWidget();
        tab_About->setObjectName(QString::fromUtf8("tab_About"));
        gridLayout_4 = new QGridLayout(tab_About);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_3);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_10);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        label_8 = new QLabel(tab_About);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        label_8->setFont(font2);
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_8);

        label_11 = new QLabel(tab_About);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_11);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

        label_9 = new QLabel(tab_About);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_9);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        label_10 = new QLabel(tab_About);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_10);


        horizontalLayout_10->addLayout(verticalLayout);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_11);


        verticalLayout_10->addLayout(horizontalLayout_10);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_4);


        gridLayout_4->addLayout(verticalLayout_10, 0, 0, 1, 1);

        tabWidget->addTab(tab_About, QString());

        verticalLayout_3->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setAutoFillBackground(false);
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "LXI Tools - lxi-gui", nullptr));
        label_Logo->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget_InstrumentList->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Instrument ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_InstrumentList->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "IP Address", nullptr));
        pushButton_Search->setText(QApplication::translate("MainWindow", "Search", nullptr));
#ifndef QT_NO_TOOLTIP
        checkBox_mDNS->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        checkBox_mDNS->setText(QApplication::translate("MainWindow", "mDNS", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "SCPI Command:", nullptr));
        pushButton_SCPI_Clear->setText(QApplication::translate("MainWindow", "Clear", nullptr));
        pushButton_SCPI_Send->setText(QApplication::translate("MainWindow", "Send", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Request/Response:", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "IEEE 488.2 Common Commands:", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_SCPI_CLS->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:large; font-weight:600;\">Clear Status Command</span></p><p>Clears the instrument status byte by emptying the error queue and clearing all event registers. Also cancels any preceding *OPC command or query.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_SCPI_CLS->setText(QApplication::translate("MainWindow", "*CLS", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_SCPI_ESE->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:large; font-weight:600;\">Event Status Enable Command</span></p><p>Sets bits in the standard event status enable register. The integer &lt;value&gt; represents the sum of the bits that will be enabled.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_SCPI_ESE->setText(QApplication::translate("MainWindow", "*ESE <value>", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_SCPI_ESEQuestion->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:large; font-weight:600;\">Event Status Enable Query</span></p><p>Reads the value of the standard event enable register.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_SCPI_ESEQuestion->setText(QApplication::translate("MainWindow", "*ESE?", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_SCPI_ESRQuestion->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:large; font-weight:600;\">Event Status Register Query</span></p><p>Reads and clears the event status register.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_SCPI_ESRQuestion->setText(QApplication::translate("MainWindow", "*ESR?", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_SCPI_IDNQuestion->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:large; font-weight:600;\">Identification Query</span></p><p>Returns a string that uniquely identifies the instrument. The string is of the form &quot;&lt;manufacturer name&gt;,&lt;model number&gt;,&lt;serial number&gt;,&lt;software revision&gt;&quot;.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_SCPI_IDNQuestion->setText(QApplication::translate("MainWindow", "*IDN?", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_SCPI_OPC->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:large; font-weight:600;\">Operation Complete Command</span></p><p>Generates the OPC message in the standard event status register when all pending overlapped operations have been completed.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_SCPI_OPC->setText(QApplication::translate("MainWindow", "*OPC", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_SCPI_OPCQuestion->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:large; font-weight:600;\">Operation Complete Query</span></p><p>Returns &quot;1&quot; when all pending overlapped operations have been completed.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_SCPI_OPCQuestion->setText(QApplication::translate("MainWindow", "*OPC?", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_SCPI_RST->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:large; font-weight:600;\">Reset Command</span></p><p>Executes a device reset and cancels any pending *OPC command or query.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_SCPI_RST->setText(QApplication::translate("MainWindow", "*RST", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_SCPI_SRE->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:large; font-weight:600;\">Service Request Enable Command</span></p><p>Sets bits in the service request enable register. The integer &lt;value&gt; represents the sum of the bits that will be enabled.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_SCPI_SRE->setText(QApplication::translate("MainWindow", "*SRE <value>", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_SCPI_SREQuestion->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:large; font-weight:600;\">Service Request Enable Query</span></p><p>Reads the value of the service request enable register.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_SCPI_SREQuestion->setText(QApplication::translate("MainWindow", "*SRE?", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_SCPI_STBQuestion->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:large; font-weight:600;\">Status Byte Query</span></p><p>Reads the value of the instrument status byte.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_SCPI_STBQuestion->setText(QApplication::translate("MainWindow", "*STB?", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_SCPI_TSTQuestion->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:large; font-weight:600;\">Self-Test Query</span></p><p>This query initiates the internal self-test and returns the result. A &quot;0&quot; indicates all tests passed. Any other value indicates one or more tests failed.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_SCPI_TSTQuestion->setText(QApplication::translate("MainWindow", "*TST?", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_SCPI_WAI->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:large; font-weight:600;\">Wait-to-Continue Command</span></p><p>Prohibits the instrument from executing any new commands until all pending overlapped commands have been completed.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_SCPI_WAI->setText(QApplication::translate("MainWindow", "*WAI", nullptr));
        pushButton_SCPI_Blank->setText(QString());
        label_22->setText(QApplication::translate("MainWindow", "SCPI 1999.0 Commands:", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_SCPI_SystemVersionQuery->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:large; font-weight:600;\">System Version Query</span></p><p>Returns supported SCPI version.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_SCPI_SystemVersionQuery->setText(QApplication::translate("MainWindow", ":SYSTem:VERSion?", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_SCPI_SystemErrorQuery->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:large; font-weight:600;\">System Error Query</span></p><p>Returns and clears the latest error message from the instrument.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_SCPI_SystemErrorQuery->setText(QApplication::translate("MainWindow", ":SYSTem:ERRor?", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_SCPI_SystemErrorNextQuery->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:large; font-weight:600;\">System Error Next Query</span></p><p><br/></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_SCPI_SystemErrorNextQuery->setText(QApplication::translate("MainWindow", ":SYSTem:ERRor:NEXT?", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_SCPIP_StatusOperationQuery->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:large; font-weight:600;\">Status Operation Query</span></p><p><br/></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_SCPIP_StatusOperationQuery->setText(QApplication::translate("MainWindow", ":STATus:OPERation?", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_SCPI_StatusPreset->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:large; font-weight:600;\">Status Preset Command</span></p><p><br/></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_SCPI_StatusPreset->setText(QApplication::translate("MainWindow", ":STATus:PRESet", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_SCPI), QApplication::translate("MainWindow", "SCPI", nullptr));
        pushButton_Screenshot_LiveView->setText(QApplication::translate("MainWindow", "Live View", nullptr));
        pushButton_Screenshot_TakeScreenshot->setText(QApplication::translate("MainWindow", "Take screenshot", nullptr));
        pushButton_Screenshot_Save->setText(QApplication::translate("MainWindow", "Save", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Screenshot), QApplication::translate("MainWindow", "Screenshot", nullptr));
        label_6->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "Send", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "requests", nullptr));
        pushButton_Benchmark_Start->setText(QApplication::translate("MainWindow", "Start", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Benchmark), QApplication::translate("MainWindow", "Benchmark", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "Data 1:", nullptr));
        lineEdit->setPlaceholderText(QApplication::translate("MainWindow", "SCPI Command", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "Data 2:", nullptr));
        lineEdit_2->setPlaceholderText(QApplication::translate("MainWindow", "SCPI Command", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "samples/second", nullptr));
        pushButton_DataRecorder_Start->setText(QApplication::translate("MainWindow", "Start", nullptr));
        pushButton_DataRecorder_Save->setText(QApplication::translate("MainWindow", "Save", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_DataRecorder), QApplication::translate("MainWindow", "Data Recorder", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "Search Timeout:", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "second(s)", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "SCPI Timeout:", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "second(s)", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "Screenshot Timeout:", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "second(s)", nullptr));
        label_21->setText(QApplication::translate("MainWindow", "Search mDNS service:", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "_lxi._tcp", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "_hislip._tcp", nullptr));
        comboBox->setItemText(2, QApplication::translate("MainWindow", "_http._tcp", nullptr));
        comboBox->setItemText(3, QApplication::translate("MainWindow", "_scpi-raw._tcp", nullptr));
        comboBox->setItemText(4, QApplication::translate("MainWindow", "_scpi-telnet._tcp", nullptr));
        comboBox->setItemText(5, QApplication::translate("MainWindow", "_vxi-11._tcp", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tab_Settings), QApplication::translate("MainWindow", "Settings", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "lxi-gui", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "VERSION", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Tools for managing LXI compatible instruments", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "lxi-tools.github.io", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_About), QApplication::translate("MainWindow", "About", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
