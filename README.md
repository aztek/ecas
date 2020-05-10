# Elementary cellular automata simulator

```
$ make
```

## [Rule 30](https://en.wikipedia.org/wiki/Rule_30)
```
$ ./ecas -r 30 -t 31 -g 32 -a '^'
                               ^
                              ^^^
                             ^^  ^
                            ^^ ^^^^
                           ^^  ^   ^
                          ^^ ^^^^ ^^^
                         ^^  ^    ^  ^
                        ^^ ^^^^  ^^^^^^
                       ^^  ^   ^^^     ^
                      ^^ ^^^^ ^^  ^   ^^^
                     ^^  ^    ^ ^^^^ ^^  ^
                    ^^ ^^^^  ^^ ^    ^ ^^^^
                   ^^  ^   ^^^  ^^  ^^ ^   ^
                  ^^ ^^^^ ^^  ^^^ ^^^  ^^ ^^^
                 ^^  ^    ^ ^^^   ^  ^^^  ^  ^
                ^^ ^^^^  ^^ ^  ^ ^^^^^  ^^^^^^^
               ^^  ^   ^^^  ^^^^ ^    ^^^      ^
              ^^ ^^^^ ^^  ^^^    ^^  ^^  ^    ^^^
             ^^  ^    ^ ^^^  ^  ^^ ^^^ ^^^^  ^^  ^
            ^^ ^^^^  ^^ ^  ^^^^^^  ^   ^   ^^^ ^^^^
           ^^  ^   ^^^  ^^^^     ^^^^ ^^^ ^^   ^   ^
          ^^ ^^^^ ^^  ^^^   ^   ^^    ^   ^ ^ ^^^ ^^^
         ^^  ^    ^ ^^^  ^ ^^^ ^^ ^  ^^^ ^^ ^ ^   ^  ^
        ^^ ^^^^  ^^ ^  ^^^ ^   ^  ^^^^   ^  ^ ^^ ^^^^^^
       ^^  ^   ^^^  ^^^^   ^^ ^^^^^   ^ ^^^^^ ^  ^     ^
      ^^ ^^^^ ^^  ^^^   ^ ^^  ^    ^ ^^ ^     ^^^^^   ^^^
     ^^  ^    ^ ^^^  ^ ^^ ^ ^^^^  ^^ ^  ^^   ^^    ^ ^^  ^
    ^^ ^^^^  ^^ ^  ^^^ ^  ^ ^   ^^^  ^^^^ ^ ^^ ^  ^^ ^ ^^^^
   ^^  ^   ^^^  ^^^^   ^^^^ ^^ ^^  ^^^    ^ ^  ^^^^  ^ ^   ^
  ^^ ^^^^ ^^  ^^^   ^ ^^    ^  ^ ^^^  ^  ^^ ^^^^   ^^^ ^^ ^^^
 ^^  ^    ^ ^^^  ^ ^^ ^ ^  ^^^^^ ^  ^^^^^^  ^   ^ ^^   ^  ^  ^
^^ ^^^^  ^^ ^  ^^^ ^  ^ ^^^^     ^^^^     ^^^^ ^^ ^ ^ ^^^^^^^^^
```

## [Rule 90](https://en.wikipedia.org/wiki/Rule_90)
```
$ ./ecas -r 90 -t 31 -a '*'
                               *
                              * *
                             *   *
                            * * * *
                           *       *
                          * *     * *
                         *   *   *   *
                        * * * * * * * *
                       *               *
                      * *             * *
                     *   *           *   *
                    * * * *         * * * *
                   *       *       *       *
                  * *     * *     * *     * *
                 *   *   *   *   *   *   *   *
                * * * * * * * * * * * * * * * *
               *                               *
              * *                             * *
             *   *                           *   *
            * * * *                         * * * *
           *       *                       *       *
          * *     * *                     * *     * *
         *   *   *   *                   *   *   *   *
        * * * * * * * *                 * * * * * * * *
       *               *               *               *
      * *             * *             * *             * *
     *   *           *   *           *   *           *   *
    * * * *         * * * *         * * * *         * * * *
   *       *       *       *       *       *       *       *
  * *     * *     * *     * *     * *     * *     * *     * *
 *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
```

## [Rule 110](https://en.wikipedia.org/wiki/Rule_110)
```
$ ./ecas -r 110 -t 31 -g 32 -w 32 -a 'J'
                               J
                              JJ
                             JJJ
                            JJ J
                           JJJJJ
                          JJ   J
                         JJJ  JJ
                        JJ J JJJ
                       JJJJJJJ J
                      JJ     JJJ
                     JJJ    JJ J
                    JJ J   JJJJJ
                   JJJJJ  JJ   J
                  JJ   J JJJ  JJ
                 JJJ  JJJJ J JJJ
                JJ J JJ  JJJJJ J
               JJJJJJJJ JJ   JJJ
              JJ      JJJJ  JJ J
             JJJ     JJ  J JJJJJ
            JJ J    JJJ JJJJ   J
           JJJJJ   JJ JJJ  J  JJ
          JJ   J  JJJJJ J JJ JJJ
         JJJ  JJ JJ   JJJJJJJJ J
        JJ J JJJJJJ  JJ      JJJ
       JJJJJJJ    J JJJ     JJ J
      JJ     J   JJJJ J    JJJJJ
     JJJ    JJ  JJ  JJJ   JJ   J
    JJ J   JJJ JJJ JJ J  JJJ  JJ
   JJJJJ  JJ JJJ JJJJJJ JJ J JJJ
  JJ   J JJJJJ JJJ    JJJJJJJJ J
 JJJ  JJJJ   JJJ J   JJ      JJJ
JJ J JJ  J  JJ JJJ  JJJ     JJ J
```