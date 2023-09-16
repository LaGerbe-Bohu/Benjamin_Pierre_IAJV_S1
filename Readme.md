### Benjamin Gerbe
### Pierre Durand

# Goap project - Documentation

## Introduction

This project is an implementation of the GOAP algorithm in C++, simulating a small population that needs to find  
an enemy and attack it to win.

## Resources and actions

The following table lists the preconditions, actions, and effects available in this world.
There are 14 actions that can take place.

| Preconditions                                             | Actions              | Effects                                            | Costs |
|-----------------------------------------------------------|----------------------|----------------------------------------------------|-------|
| Having 1 bread                                            | Create a villager    | +1 Villager                                        | 1     |
| Having a free villager                                    | Cutting wood         | +1 wood<br> +1 villager                            | 2     |
| Having a free villager                                    | Mining iron          | +1 iron<br> +1 villager                            | 2     |
| Having a free villager                                    | Mining gold          | +1 gold<br> +1 villager                            | 2     |
| Having a free villager<br>Having 5 wood                   | Build a farm         | +1 farm                                            | 3     |
| Having a farm<br>Having a free villager                   | Make bread           | +1 bread<br> +1 villager                           | 2     |
| Having iron<br>Having gold<br>Having bread                | Create a warrior     | +1 warrior                                         | 5     |
| Spotted an enemy<br>Having 10 warriors<br>Having a church | Attack the enemy     | -10 warriors<br>-10 enemy HP                       | 10    |
| Having a warrior                                          | Search for the enemy | +1 enemy spotted                                   | 5     |
| Having a free villager                                    | Mine stone           | +1 stone                                           | 2     |
| Having stone<br>Having a priest<br>Having wood            | Build a church       | +1 church                                          | 2     |
| Having a free villager<br>Having wood<br>                 | Make wine            | +1 wine                                            | 2     |
| Having a party<br>Having gold                             | Create a priest      | +1 priest                                          | 2     |
| Having a free villager<br>Having gold<br>Having wine      | Do a big party       | +1 big party<br>Taste the wine while partying hard | 10    |

## Optimizations

It takes on average 0.0077 seconds for the program to run.

- [x] Strings are passed as reference in the functions parameters.  
- [x] Usage of forward class declarations in headers.
- [x] Program is ran in release environment.
- [x] Asserts were used do simplify debugging during development
