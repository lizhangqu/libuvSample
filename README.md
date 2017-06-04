### Yaml

将yaml-cpp移植到android上的sample

### 安装boost

```
brew update
brew install boost
brew upgrade boost
```


### 编译so

```
 ./gradlew :library:externalNativeBuildDebug
 ./gradlew :library:externalNativeBuildRelease
```