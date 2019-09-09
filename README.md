# scankey

Scan Key Event Test on STM32 projects
> Develope on a the top of a famous key-scan sample online

- "trg" flag rised on press
- Single click triggered on release.
- Long press triggered on timeout, and do not have single click first within the debouncing time.
- Software debouncing
- Support both PULLDOWN and PULLUP buttons
    > pre-defined in header file

