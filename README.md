# CMake issue repro

    % cmake -GNinja .; ninja
    -- The C compiler identification is AppleClang 6.0.0.6000054
    -- The CXX compiler identification is AppleClang 6.0.0.6000054
    -- Check for working C compiler using: Ninja
    -- Check for working C compiler using: Ninja -- works
    -- Detecting C compiler ABI info
    -- Detecting C compiler ABI info - done
    -- Check for working CXX compiler using: Ninja
    -- Check for working CXX compiler using: Ninja -- works
    -- Detecting CXX compiler ABI info
    -- Detecting CXX compiler ABI info - done
    -- Configuring done
    -- Generating done
    -- Build files have been written to: /Users/pcarrier/tmp/repro
    ninja: error: 'boost-prefix/lib/libboost_system.a', needed by 'foo', missing and no     known rule to make it
    zsh: exit 1     ninja
