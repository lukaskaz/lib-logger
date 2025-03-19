# lib-logger
Library for program tracing logs
<br><br>
**Example of the output (w/ crit logs and w/ debug logs):**<br>
pi@raspberrypi:\~/git/lib-logger/build$ ./examples/group/prog 2 0 0<br>
[CRIT] Additional test log<br>
[CRIT] More information here<br>
pi@raspberrypi:\~/git/lib-logger/build$ cat ./logs/traces.log<br>
Logging started at Wed Mar 19 14:24:45 2025<br>
[CRIT] Additional test log<br>
[CRIT] More information here<br>
pi@raspberrypi:\~/git/lib-logger/build$ ./examples/group/prog 2 1 0<br>
[20250319_142449_553768][CRIT] Additional test log<br>
[20250319_142449_553768][CRIT] More information here<br>
pi@raspberrypi:\~/git/lib-logger/build$ cat ./logs/traces.log<br>
Logging started at Wed Mar 19 14:24:49 2025<br>
[20250319_142449_553810][CRIT] Additional test log<br>
[20250319_142449_553810][CRIT] More information here<br>
pi@raspberrypi:\~/git/lib-logger/build$ ./examples/group/prog 2 1 1<br>
[20250319_142454_564008][CRIT][tag] Additional test log<br>
[20250319_142454_564008][CRIT][tag] More information here<br>
pi@raspberrypi:\~/git/lib-logger/build$ cat ./logs/traces.log<br>
Logging started at Wed Mar 19 14:24:54 2025<br>
[20250319_142454_564027][CRIT][tag] Additional test log<br>
[20250319_142454_564027][CRIT][tag] More information here<br>
pi@raspberrypi:\~/git/lib-logger/build$ ./examples/group/prog 2 0 1<br>
[CRIT][tag] Additional test log<br>
[CRIT][tag] More information here<br>
pi@raspberrypi:\~/git/lib-logger/build$ cat ./logs/traces.log<br>
Logging started at Wed Mar 19 14:24:59 2025<br>
[CRIT][tag] Additional test log<br>
[CRIT][tag] More information here<br>
pi@raspberrypi:\~/git/lib-logger/build$ ./examples/group/prog 3 0 0<br>
[INFO] Test log number one<br>
[CRIT] Additional test log<br>
[CRIT] More information here<br>
pi@raspberrypi:\~/git/lib-logger/build$ cat ./logs/traces.log<br>
Logging started at Wed Mar 19 14:25:05 2025<br>
[INFO] Test log number one<br>
[CRIT] Additional test log<br>
[CRIT] More information here<br>
pi@raspberrypi:\~/git/lib-logger/build$ ./examples/group/prog 3 1 0<br>
[20250319_142511_956484][INFO] Test log number one<br>
[20250319_142511_956513][CRIT] Additional test log<br>
[20250319_142511_956513][CRIT] More information here<br>
pi@raspberrypi:\~/git/lib-logger/build$ cat ./logs/traces.log<br>
Logging started at Wed Mar 19 14:25:11 2025<br>
[20250319_142511_956506][INFO] Test log number one<br>
[20250319_142511_956519][CRIT] Additional test log<br>
[20250319_142511_956519][CRIT] More information here<br>
pi@raspberrypi:\~/git/lib-logger/build$ ./examples/group/prog 3 1 1<br>
[20250319_142525_974779][INFO][tag] Test log number one<br>
[20250319_142525_974806][CRIT][tag] Additional test log<br>
[20250319_142525_974806][CRIT][tag] More information here<br>
pi@raspberrypi:\~/git/lib-logger/build$ cat ./logs/traces.log<br>
Logging started at Wed Mar 19 14:25:25 2025<br>
[20250319_142525_974799][INFO][tag] Test log number one<br>
[20250319_142525_974812][CRIT][tag] Additional test log<br>
[20250319_142525_974812][CRIT][tag] More information here<br>
pi@raspberrypi:\~/git/lib-logger/build$ ./examples/group/prog 3 0 1<br>
[INFO][tag] Test log number one<br>
[CRIT][tag] Additional test log<br>
[CRIT][tag] More information here<br>
pi@raspberrypi:\~/git/lib-logger/build$ cat ./logs/traces.log<br>
Logging started at Wed Mar 19 14:25:33 2025<br>
[INFO][tag] Test log number one<br>
[CRIT][tag] Additional test log<br>
[CRIT][tag] More information here<br>
