package org.gjs.java.test.util;

import static org.junit.jupiter.api.Assertions.fail;

import java.util.ArrayList;
import java.util.List;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.test.BaseUnitTest;
import org.gjs.java.test.tester.ToStringTester;
import org.junit.jupiter.api.Test;

import com.openpojo.validation.test.Tester;

class PojoUtilsTest extends BaseUnitTest<PojoUtils> {

	@Test
	void testTestPojo1() {
		try {
			Tester tester = null;
			PojoUtils.testPojo(tester, "org.gjs.java.test.samples.pojos");
			tester = new ToStringTester();
			PojoUtils.testPojo(tester, "org.gjs.java.test.samples.pojos");
			PojoUtils.testPojo(tester, null);
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Recibida excepcion");
		}
	}

	@Test
	void testTestPojo3() {
		try {
			List<Tester> testers = null;
			PojoUtils.testPojo(testers, "org.gjs.java.test.samples.pojos");
			testers = new ArrayList<>();
			PojoUtils.testPojo(testers, "org.gjs.java.test.samples.pojos");
			PojoUtils.testPojo(testers, "org.gjs.java.test.samples.pojos");
			PojoUtils.testPojo(testers, null);
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Recibida excepcion");
		}
	}

}
