# cocos2d-parallax-scene
A simple, lightweight, maintainable parallax scene built with cocos2dx

## Clone Repo
Open terminal and go to your working directory. Then execute below commands

1. 
    git clone git@github.com:mdfaizulislam/cocos2d-parallax-scene.git
  
2. 
    cd cocos2d-parallax-scene
  
3. 
    code .

## Steps to Android Build
1. Open proj.android in Android-Studio.
2. Open proj.android/local.properties file in editor and update android sdk and ndk directory
3. Open proj.android/build.gradle file and update gradle version as below classpath

    'com.android.tools.build:gradle:<some_version>’
    to classpath
    'com.android.tools.build:gradle:4.1.2'
    or
    classpath 'com.android.tools.build:gradle:7.4.1'

4. Open proj.android/gradle/gradle-wrapper.properties and update distributionURL as

    belowdistributionUrl=https\://services.gradle.org/distributions/gradle-<some_version>-bin.zi
    to
    distributionUrl=https\://services.gradle.org/distributions/gradle-6.5-bin.zip
    or
    distributionUrl=https\://services.gradle.org/distributions/gradle-7.5-all.zip
5. Now sync the project.
6. Once sync is done, run the project in Android emulator/external device and build apk
