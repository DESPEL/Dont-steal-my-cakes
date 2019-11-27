# Como crear patrones de ataque

Para crear un patron de ataque se agrega a Levels.h
```
    if (name == "<nombre del patron>") {
            // obtener patron de movimiento para las balas
			auto test1 = MovementPatterns::create("test1");

			patterns[name] = AttackPattern(
			    // Argumento 1: tiempo de aparicion luego de la anterior
			    // Argumento 2: BasicBullet con creado con la imagen de la bala
			    // patron de movimiento de la bala
				std::make_tuple(0.0f, BasicBullet::create("redbullet.png"), test1.get(0.0f)),
				... // balas disparadas
				std::make_tuple(0.2f, BasicBullet::create("redbullet.png"), test1.get(20.0f))
			);

			return patterns[name];
		}
```
