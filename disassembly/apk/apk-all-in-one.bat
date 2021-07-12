apktool b ./com.dc.hwsj
apksigner sign --ks signing-key.jks -ks-pass pass:123123 ./com.dc.hwsj/dist/com.dc.hwsj.apk
PAUSE