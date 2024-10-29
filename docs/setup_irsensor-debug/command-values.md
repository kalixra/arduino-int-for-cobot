## IR Remote Control Button Layout

The following table shows the command values for each button on the Elegoo IR remote. Please note that not all IR remotes use the same command values, so these values may vary with different remotes. To verify the values for your remote, use the `setup_ir_system-debug.ino` sketch, which will print the command codes for each button to the Serial Monitor.

```
| IR REMOTE CONTROL BUTTON | Command = VALUE |
|--------------------------|-----------------|
| Power                    | 0x45            |
| VOL+                     | 0x46            |
| VOL-                     | 0x15            |
| FUNC/STOP                | 0x47            |
| |<< (Rewind)             | 0x44            |
| >|| (Play/Pause)         | 0x40            |
| >>| (Fast Forward)       | 0x43            |
| Arrow Down               | 0x7             |
| Arrow Up                 | 0x9             |
| EQ                       | 0x19            |
| ST/REPT                  | 0xD             |
| 0                        | 0x16            |
| 1                        | 0xC             |
| 2                        | 0x18            |
| 3                        | 0x5E            |
| 4                        | 0x8             |
| 5                        | 0x1C            |
| 6                        | 0x5A            |
| 7                        | 0x42            |
| 8                        | 0x52            |
| 9                        | 0x4A            |
```
