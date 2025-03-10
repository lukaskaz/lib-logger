# lib-logger
Library for program tracing logs
<br><br>
**Example of the output (w/ crit logs and w/ debug logs):**<br>
pi@raspberrypi:\~/git/lib-logger/build $ ./examples/group/prog 2 0<br>
[CRIT] Additional test log<br>
[CRIT] More information here<br>
pi@raspberrypi:\~/git/lib-logger/build $ cat ./logs/traces.log <br>
Logging started at Mon Mar 10 09:38:15 2025<br>
[CRIT] Additional test log<br>
[CRIT] More information here<br>
pi@raspberrypi:\~/git/lib-logger/build $ ./examples/group/prog 2 1<br>
[CRIT][tag] Additional test log<br>
[CRIT][tag] More information here<br>
pi@raspberrypi:\~/git/lib-logger/build $ cat ./logs/traces.log <br>
Logging started at Mon Mar 10 09:38:22 2025<br>
[CRIT][tag] Additional test log<br>
[CRIT][tag] More information here<br>
pi@raspberrypi:\~/git/lib-logger/build $ ./examples/group/prog 3 0<br>
[INFO] Test log number one<br>
[CRIT] Additional test log<br>
[CRIT] More information here<br>
pi@raspberrypi:\~/git/lib-logger/build $ cat ./logs/traces.log <br>
Logging started at Mon Mar 10 09:38:46 2025<br>
[INFO] Test log number one<br>
[CRIT] Additional test log<br>
[CRIT] More information here<br>
pi@raspberrypi:\~/git/lib-logger/build $ ./examples/group/prog 3 1<br>
[INFO][tag] Test log number one<br>
[CRIT][tag] Additional test log<br>
[CRIT][tag] More information here<br>
pi@raspberrypi:\~/git/lib-logger/build $ cat ./logs/traces.log <br>
Logging started at Mon Mar 10 09:38:55 2025<br>
[INFO][tag] Test log number one<br>
[CRIT][tag] Additional test log<br>
[CRIT][tag] More information here<br>
