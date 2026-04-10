#set( $symbol_pound = '#' )
#set( $symbol_dollar = '$' )
#set( $symbol_escape = '\' )
#set( $capitalizedName = $shortName.substring(0,1).toUpperCase() + $shortName.substring(1))
${symbol_pound}
${symbol_pound} Program ${capitalizedName} Rest Client 
${symbol_pound}
${symbol_pound} Module Models.py
${symbol_pound}


from __future__ import annotations

from pydantic import AwareDatetime, BaseModel, Field


class ServerStatus(BaseModel):
    status: str = Field(..., examples=['OK'])
    date_time: AwareDatetime = Field(
        ..., alias='date-time', examples=['2026-03-22T09:50:00Z']
    )
