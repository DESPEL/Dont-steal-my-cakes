# Como crear patrones de movimiento

Para crear un patron de movimiento se agrega a Levels.h
```
    if (name == "<nombre del patron>") {
        patterns[name] = MovementPattern(
                // argumento 1: tiempo del movmiento
                // argumento 2: desplazamiento
				std::make_tuple(1.0f, cocos2d::Vec2(100, 0)),
				std::make_tuple(10.0f, cocos2d::Vec2(0, 0))
			);
			return patterns[name];
    }
```
