# CDC [![Build Status](https://travis-ci.org/Felipe-Thorn/CDC.svg?branch=master)](https://travis-ci.org/Felipe-Thorn/CDC) [![Coverity Status](https://scan.coverity.com/projects/14981/badge.svg)](https://scan.coverity.com/projects/felipe-thorn-cdc?tab=overview) [![Quality Gate](https://sonarqube.com/api/badges/gate?key=felipe-thorn-github)](https://sonarqube.com/dashboard/index/felipe-thorn-github)
A Continuous Delivery set of tools for C language

# CMake

## Warning about find_library
To acess a library, she must have been created and installed first.

If the same cmake execution tries to create those files and acess then, there will be problems.

The install of the libs only happen at "make install" and this can only happen whem the cmake command finishes. 
That said, find_library wouldn't be able to actually find libraries, for they are not installed yet.


# GitHub and Travis CI

## Not every commit should trigger the build

Add [ci skip] to the commit message, so it won't trigger a new build.

#### You can find more details in the![ wiki pages](https://github.com/Felipe-Thorn/CDC/wiki)
