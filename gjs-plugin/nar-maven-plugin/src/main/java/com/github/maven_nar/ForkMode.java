package com.github.maven_nar;

public enum ForkMode {
	NEVER("never", 0, false), ONCE("once", 1, false), ALWAYS("always", 1, true), PERTHREAD("perthead", -1, false);

	private String name;
	private int forkCount;
	private boolean reuseForks;

	ForkMode(String name, int forkCount, boolean reuseForks) {
		this.name = name;
		this.forkCount = forkCount;
		this.reuseForks = reuseForks;
	}

	public String getName() {
		return name;
	}

	public int getForkCount() {
		return forkCount;
	}

	public boolean isReuseForks() {
		return reuseForks;
	}

	@Override
	public String toString() {
		return name;
	}

	public final boolean equals(String other) {
		return name.equals(other);
	}

	public static ForkMode get(String name) {
		ForkMode mode = NEVER;
		if (ALWAYS.getName().equals(name)) {
			mode = ALWAYS;
		} else if (ONCE.getName().equals(name)) {
			mode = ONCE;
		} else if (PERTHREAD.getName().equals(name)) {
			mode = PERTHREAD;
		}
		return mode;
	}

}
