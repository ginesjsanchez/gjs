package org.gjs.java.common.util;

import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;

import java.io.IOException;
import java.sql.SQLRecoverableException;

import org.gjs.java.common.util.ExceptionUtils;
import org.gjs.java.test.BaseClassTest;
import org.junit.jupiter.api.Test;

public class ExceptionUtilsTest extends BaseClassTest<ExceptionUtils> {

	@Test
	public void testFindCauseOfClass() {
		Exception ex = null;
		Exception cause = ExceptionUtils.findCauseOfClass(ex, SQLRecoverableException.class);
		assertNull(cause);
		ex = new RuntimeException();
		cause = ExceptionUtils.findCauseOfClass(ex, SQLRecoverableException.class);
		assertNull(cause);
		ex = new IOException();
		cause = ExceptionUtils.findCauseOfClass(ex, SQLRecoverableException.class);
		assertNull(cause);
		ex = new SQLRecoverableException(ex);
		cause = ExceptionUtils.findCauseOfClass(ex, SQLRecoverableException.class);
		assertNotNull(cause);
		// ex = new JDBCConnectionException("could not extract ResultSet",
		// (SQLException) ex);
		// cause = ExceptionUtil.findCauseOfClass(ex, SQLRecoverableException.class);
		// assertNotNull(cause);
		// ex = new DataAccessResourceFailureException("could not extract ResultSet",
		// ex);
		// cause = ExceptionUtils.findCauseOfClass(ex, SQLRecoverableException.class);
		// assertNotNull(cause);
	}

}
