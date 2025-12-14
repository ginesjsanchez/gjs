package org.gjs.java.common.task;

import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;

import org.gjs.java.common.task.BaseTask;
import org.gjs.java.common.task.TaskResult;
import org.gjs.java.test.BaseUnitTest;
import org.junit.jupiter.api.Test;

import lombok.Getter;

class BaseTaskTest extends BaseUnitTest<BaseTask> {

	@Getter
	static class SampleTask1 extends BaseTask {

		private boolean executed;

		public SampleTask1() {
			super("jobName", 1, "taskName", "taskDescription");
			executed = false;
		}

		@Override
		protected void executeTask(TaskResult result) throws Exception {
			executed = true;
		}

	}

	@Getter
	static class SampleTask2 extends BaseTask {

		private boolean executed;

		public SampleTask2() {
			super("jobName", 1, "taskName", "taskDescription");
			executed = false;
		}

		@Override
		protected void executeTask(TaskResult result) throws Exception {
			executed = true;
			throw new RuntimeException("Error test");
		}

	}

	@Test
	void testBaseTask1() {
		final SampleTask1 task = new SampleTask1();
		assertFalse(task.isExecuted());
		task.run();
		assertTrue(task.isExecuted());
	}

	@Test
	void testBaseTask2() {
		final SampleTask2 task = new SampleTask2();
		assertFalse(task.isExecuted());
		task.run();
		assertTrue(task.isExecuted());
	}

}
