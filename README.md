### SEassign
Tagineer Dai
##### TODO list after mid-term inspection [2017-4-17]

+ uncouple the TcpSocket and GUI
+ fix the hard-coded bug
  - listen port/ host port/ host addr should be added to loginWindow
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
