# itkBullseye
Create a dicom image with a bullseye

* I could use vtk - somewhat an overkill
* http://dicom.nema.org/dicom/2013/output/chtml/part03/sect_C.9.html
* http://dicom.nema.org/medical/dicom/2017d/output/chtml/part03/sect_C.9.2.html

| System   |     Status      |
|----------|:---------------:|
| [OSX/Linux build - Travis][travis_link]   | [![Travis (.org)][travis_badge]][travis_link]                      |
| [Windows build - AppVeyor][appveyor_link] | [![AppVeyor][appveyor_badge]][appveyor_link]                       |
| [Downloads][downloads_link]               | [![GitHub Releases (by Release)][downloads_badge]][downloads_link] |


# Notes

## How to set or access env variables

```c++
    const char* env_p = std::getenv("CustomerIceProgs");
    if (env_p)
        std::cout << env_p << std::endl;
    else {
        std::cout << "no env_p" << std::endl;
        return 1; //EXIT_FAILURE
    }
    putenv("CustomerIceProgs=../../tests/testData/models");
    std::string rootFolder(std::getenv("CustomerIceProgs")); 
```

[travis_badge]: https://img.shields.io/travis/MRKonrad/itkBullseye/master.svg?style=flat-square
[travis_link]: https://travis-ci.org/MRKonrad/itkBullseye
[appveyor_badge]: https://img.shields.io/appveyor/ci/MRKonrad/itkBullseye/master.svg?style=flat-square
[appveyor_link]: https://ci.appveyor.com/project/MRKonrad/itkBullseye
[codecov_badge]: https://img.shields.io/codecov/c/github/MRKonrad/itkBullseye.svg?style=flat-square
[codecov_link]: https://codecov.io/gh/MRKonrad/itkBullseye
[downloads_link]: https://github.com/MRKonrad/itkBullseye/releases
[downloads_badge]: https://img.shields.io/github/downloads/MRKonrad/itkBullseye/total.svg?style=flat-square
