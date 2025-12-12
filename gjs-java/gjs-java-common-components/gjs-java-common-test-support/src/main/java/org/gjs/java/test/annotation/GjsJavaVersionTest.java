package org.gjs.java.test.annotation;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.condition.EnabledForJreRange;
import org.springframework.core.annotation.AliasFor;

@Test
@EnabledForJreRange
public @interface GjsJavaVersionTest {

	@AliasFor(annotation = EnabledForJreRange.class, attribute = "minVersion")
	int minVersion() default -1;

	@AliasFor(annotation = EnabledForJreRange.class, attribute = "maxVersion")
	int maxVersion() default -1;

}
