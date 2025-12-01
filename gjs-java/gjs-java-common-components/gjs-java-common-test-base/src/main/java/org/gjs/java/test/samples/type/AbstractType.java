package org.gjs.java.test.samples.type;

public abstract class AbstractType {

    private String value;

    public abstract String getName();
	public abstract void setName(String name);
	
    public String getValue() {
        return value;
    }

    public void setValue(String value) {
        this.value = value;
    }
}
