package org.gjs.java.common;

import static org.junit.jupiter.api.Assertions.assertEquals;

import org.gjs.java.test.BaseClassTest;
import org.junit.jupiter.api.Test;

class CalculusUtilsTest extends BaseClassTest<CalculusUtils> {

	@Test
	void testEpsilon() {
		assertEquals(Math.ulp((float) 1.0), CalculusUtils.epsilonFloat());
		assertEquals(Math.ulp(1.0), CalculusUtils.epsilonDouble());
	}

}
