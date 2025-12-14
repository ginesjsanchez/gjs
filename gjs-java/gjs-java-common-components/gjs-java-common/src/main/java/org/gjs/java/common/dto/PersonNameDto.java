package org.gjs.java.common.dto;

import org.apache.commons.lang3.builder.ToStringBuilder;
import org.apache.commons.lang3.builder.ToStringStyle;

import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
public abstract class PersonNameDto {

	protected String name;

	protected String firstSurname;

	public abstract String getFullName();

	public abstract String getFormattedFullName();

	@Override
	public abstract PersonNameDto clone();

	/*
	 * (non-Javadoc)
	 *
	 * @see java.lang.Object#toString()
	 */

	@Override
	public String toString() {
		return new ToStringBuilder(this, ToStringStyle.SHORT_PREFIX_STYLE).append("fullName", getFullName()).toString();
	}

}
