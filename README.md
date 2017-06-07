### SEassign  
Tagineer Dai  

##### TODO list after mid-term inspection [2017-4-17]

+ uncouple the TcpSocket and GUI
+ fix the hard-coded bug
  - the auto change of temperature should be added to ConfigAC and config parser
+ Design a new interface
  - At client, the target temperature and wind ratio should support sended at the same time.
  - Restrictive of Quit, Close and ConnectErrors
+ Client
  - Release dependence to Request
  - decrease member of status
  - Add manipulate of ONC->OFFC
+ Server
  - dispatch of request
  - controled change of temperature
  - Statues -> Table
  - Request list -> Table/Database
  - NEED for statistic?
  - Design the Log
  - A driver for Database->LogFile given B/E of time  

##### 2017-4-28  
+ The hard-coded bug fixed in the LoginWindow.

##### 2017-6-6
+ The Server with dispatch and logfile.
+ Refine message flow.

##### 2017-6-7
+ Fixed some GUI bugs related to TableWidget.
+ Hand in Homework.
