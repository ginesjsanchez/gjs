package org.gjs.java.util;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.fail;

import java.util.concurrent.CountDownLatch;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.exception.GjsException;
import org.gjs.java.supplier.random.RandomAlphanumericStringSupplier;
import org.gjs.java.test.BaseUnitTest;
import org.junit.jupiter.api.Test;

import lombok.Getter;

public class AesUtilConcurrencyTest extends BaseUnitTest<AesUtil> {

	RandomAlphanumericStringSupplier stringSupplier;

	@Getter
	public class SingleProbe {

		private int count;
		private int ok;

		public synchronized int increment() {
			return count++;
		}

		public synchronized int incrementOk() {
			return ok++;
		}

		public void test() {
			try {
				final int id = increment();
				final String plain = stringSupplier.get();
				final String encrypted = AesUtil.encryptString(plain);
				final String decrypted = AesUtil.decryptString(encrypted);
				logger.info("Id {}: {} => {}", id, plain, encrypted);
				if (plain.equals(decrypted)) {
					incrementOk();
				} else {
					logger.error(String.format("Error encrypt/decrypt plain:{}", plain));
				}
			} catch (final GjsException e) {
				logger.error(ExceptionUtils.getStackTrace(e));
			}
		}
	}

	@Override
	protected void initialize() throws Exception {
		stringSupplier = new RandomAlphanumericStringSupplier(35, false, false);
	}

	@Test
	public void testConcurrency() throws InterruptedException {
		final int numberOfThreads = 100;
		final ExecutorService service = Executors.newFixedThreadPool(numberOfThreads);
		final CountDownLatch latch = new CountDownLatch(numberOfThreads);
		final SingleProbe probe = new SingleProbe();
		for (int i = 0; i < numberOfThreads; i++) {
			service.submit(() -> {
				try {
					probe.test();
				} catch (final Exception e) {
					logger.error(ExceptionUtils.getStackTrace(e));
					fail("Excepcion recibida");
				}
				latch.countDown();
			});
		}
		latch.await();
		assertEquals(numberOfThreads, probe.getCount());
		assertEquals(numberOfThreads, probe.getOk());
	}

}
