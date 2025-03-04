# lib-logger
Library for program tracing logs
<br><br>
**Example of the output (w/ crit logs and w/ debug logs):**<br>
pi@raspberrypi:\~/git/lib-logger/build $ ./examples/group/prog 2<br>
[CRIT][tag] Additional test log<br>
[CRIT][tag] More information here<br>
pi@raspberrypi:\~/git/lib-logger/build $ cat ./logs/traces.log <br>
Logging started at Tue Mar  4 14:26:14 2025<br>
[CRIT][tag] Additional test log<br>
[CRIT][tag] More information here<br>
pi@raspberrypi:\~/git/lib-logger/build $ ./examples/group/prog 3<br>
[INFO][tag] Test log number one<br>
[CRIT][tag] Additional test log<br>
[CRIT][tag] More information here<br>
pi@raspberrypi:\~/git/lib-logger/build $ cat ./logs/traces.log <br>
Logging started at Tue Mar  4 14:26:26 2025<br>
[INFO][tag] Test log number one<br>
[CRIT][tag] Additional test log<br>
[CRIT][tag] More information here<br>
