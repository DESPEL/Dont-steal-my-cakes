# Como crear niveles

Para crear un nivel se agrega a Levels.h
```
    if (name == "<nombre del nivel creado>") {
    
        // Crear Enemigos del nivel
        cocos2d::Vec2 pos = cocos2d::Vec2(400, 300)
        // obtener un patron de movimiento para el enemigo
        auto test = MovementPatterns::create("test");
        // obtener un patron de ataque para el enemigo
        auto test2 = AttackPatterns::create("test");
        
        // crear el enemigo
        auto movement =  test.get(-90);
        auto attackPatternT = test2.get(movement)
        Enemy* testenemy = Enemy::create("enemigo1.png", movement, AttackPatternT, pos);
        
        // crear el nivel
        levels[name] = Level(
                // primer argumento: tiempo de aparición en comparacion al anterior
                // enemigo (se pueden reutilziar los ya creados)
				std::make_tuple(1.0f, testenemy),
				std::make_tuple(1.0f, testenemy)
		);
		
		return levels.at(name);
    }
```
